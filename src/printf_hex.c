#include "ft_printf.h"

static int	what_hex_len(unsigned int n)
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

static char	*uint_to_hex(unsigned int n, char format)
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