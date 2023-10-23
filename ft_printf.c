#include <unistd.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

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
    
    const char *str = "TEST: %d";
	int s = INT_MIN;
    int cu = ft_printf(str, s);
	int og = printf(str, s);
	write(1, "\n", 1);
	printf("\n\nprintf:\t\t%d\nft_printf:\t%d\n", og, cu);
    return 0;
}
