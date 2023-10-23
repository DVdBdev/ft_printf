#include "ft_printf.h"

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
	if (ptr_val == 0)
		return (printf_string("(nil)"));
	else
	{
		len = len + printf_string("0x");
		put_hex(ptr_val);
		len = len + ptr_len(ptr_val);
	}
	return (len);
}