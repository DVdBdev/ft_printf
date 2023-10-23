#include "ft_printf.h"

int	printf_percent(void)
{
	int	len;

	len = 0;
	len = len + printf_char('%');
	return (len);
}