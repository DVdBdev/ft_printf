/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 00:01:36 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/24 00:01:36 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>

int	printf_char(int c);
int	printf_string(char *str);
int	printf_int(int n);
int	printf_unsigned_int(unsigned int n);
int	printf_percent(void);
int	printf_hex_lower(unsigned int n);
int	printf_hex_upper(unsigned int n);
int	printf_pointer(void *ptr);
int	ft_printf(const char *str, ...);

#endif