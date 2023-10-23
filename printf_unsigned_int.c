/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 00:02:02 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/24 00:11:53 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printf_unsigned_int_len(unsigned int n)
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

static char	*uint_to_str(unsigned int n)
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
