#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

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


int	printf_formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = len + printf_char(va_arg(args, int));
	else if (format == 's')
		len = len + printf_string(va_arg(args, char *));
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

int     main(void)
{
        int a = 'a';
        char *str = "hey";
	printf("HALLO IK BEN DRIES %c %s", a, str);
        //ft_printf("HALLO IK BEN DRIES %c %c", a, b);
        return (0);
}
