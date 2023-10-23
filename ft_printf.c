#include <unistd.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

int     printf_char(int c)
{
        write(1, &c, 1);
        return (1);
}

int	printf_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	printf_positive_int(int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len = len + printf_positive_int(n / 10);
	len = len + printf_char('0' + n % 10);
	return (len);
}

int	printf_int(int n)
{
	int		len;
	char	*int_min_str;

	len = 0;
	int_min_str = "-2147483648";
	if (n == INT_MIN)
		len = printf_string(int_min_str);
	else
	{
		if (n < 0)
		{
			len = len + write(1, "-", 1);
			n = -n;
		}
		len = len + printf_positive_int(n);
	}
	return (len);
}

int	printf_unsigned_int_len(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

//TODO: malloc needs to be protected
char	*uint_to_str(unsigned int n)
{
	int		uint_len;
	char	*str;

	uint_len = printf_unsigned_int_len(n);
	str = (char *)malloc(sizeof(char) * (uint_len + 1));
	if (!str)
		return (0);
	str[uint_len] = '\0';
	while (n != 0)
	{
		str[uint_len - 1] = n % 10 + '0';
		n = n / 10;
		uint_len--;
	}
	return (str);
}

int	printf_unsigned_int(unsigned int n)
{
	int		uint_len;
	char	*str;

	uint_len = 0;
	if (n == 0)
		uint_len = uint_len + write(1, "0", 1);
	else 
	{
		str = uint_to_str(n);
		uint_len = uint_len + printf_string(str);
		free(str);
	}
	return (uint_len);
}

int	printf_percent(void)
{
	int	len;

	len = 0;
	len = len + printf_char('%');
	return (len);
}

int	what_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	if (len > 0)
		return (len);
	else
		return (1);
}

char	*uint_to_hex(unsigned int n, char format)
{
	const char	*hex_chars;
	int			hex_len;
	char		*hex_str;
	int			rem;

	if (format == 'x')
		hex_chars = "0123456789abcdef";
	else
		hex_chars = "0123456789ABCDEF";
	hex_len = what_hex_len(n);
	hex_str = (char*)malloc(hex_len + 1);
	if (!hex_str)
		return (NULL);
	hex_str[hex_len] = '\0';
	while (hex_len - 1 >= 0)
	{
		rem = n % 16;
		hex_str[hex_len - 1] = hex_chars[rem];
		n /= 16;
		hex_len--;
	}
	return (hex_str);
}

int	printf_hex_lower(unsigned int n)
{
	int		len;
	char	*str;
	
	len = 0;
	str = uint_to_hex(n, 'x');
	len = len + printf_string(str);
	free(str);
	return (len);
}

int	printf_hex_upper(unsigned int n)
{
	int		len;
	char	*str;
	
	len = 0;
	str = uint_to_hex(n, 'X');
	len = len + printf_string(str);
	free(str);
	return (len);
}

int	ptr_len(uintptr_t n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	put_hex(uintptr_t n)
{
	if (n >= 16)
	{
		put_hex(n / 16);
		put_hex(n % 16);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
}

int	printf_pointer(void *ptr)
{
	uintptr_t	ptr_val;
	int			len;

	ptr_val = (uintptr_t)ptr;
	len = 0;
	len = len + printf_string("0x");
	if (ptr_val == 0)
		len = len + printf_char('0');
	else
	{
		put_hex(ptr_val);
		len = len + ptr_len(ptr_val);
	}
	return (len);
}

int	printf_formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = len + printf_char(va_arg(args, int));
	else if (format == 's')
		len = len + printf_string(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		len = len + printf_int(va_arg(args, int));
	else if (format == 'u')
		len = len + printf_unsigned_int(va_arg(args, unsigned int));
	else if (format == '%')
		len = len + printf_percent();
	else if (format == 'x')
		len = len + printf_hex_lower(va_arg(args, unsigned int));
	else if (format == 'X')
		len = len + printf_hex_upper(va_arg(args, unsigned int));
	else if (format == 'p')
		len = len + printf_pointer(va_arg(args, void *));
	
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	va_list	args;
	int	len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len = len + printf_formats(args, str[i + 1]);
			i++;
		}
		else
			len = len + printf_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int main(void) {
	int *ptr;
	char *test = "this is a test:";
	int c = 'c';
	int i = INT_MIN;
	int d = INT_MAX;
	unsigned int u = UINT_MAX;

    ft_printf("%s %p %c %% %d %i %u %x %X\n", test, ptr, c, d, i, u, i, d);
	printf("%s %p %c %% %d %i %u %x %X\n", test, ptr, c, d, i, u, i, d);

    return (0);
}