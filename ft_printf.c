#include "ft_printf.h"

static int	printf_formats(va_list args, const char format)
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

/*int main(void) {
	int *ptr;
	char *test = "this is a test:";
	int c = 'c';
	int i = INT_MIN;
	int d = INT_MAX;
	unsigned int u = UINT_MAX;

    int a = ft_printf("%s %p %c %% %d %i %u %x %X\n", test, ptr, c, d, i, u, i, d);
	int b = printf("%s %p %c %% %d %i %u %x %X\n", test, ptr, c, d, i, u, i, d);
	printf("ft_printf:\t%d\nprintf:\t\t%d\n", a, b);

    return (0);
}*/