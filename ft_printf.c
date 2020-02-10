/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:17:49 by eassouli          #+#    #+#             */
/*   Updated: 2020/02/10 19:15:08 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_values(t_data *data)
{
	data->width = 0;
	data->precision = -1;
	data->minus = 0;
	data->zero = 0;
}

int			isarg(int c)
{
	int	i;

	i = 0;
	while (ARGS[i] != 0)
		if (c == ARGS[i++])
			return (1);
	return (-1);
}

void		check_arg(const char *str, t_data *data, va_list ap)
{
	if (*str == 'c')
		putchar_lobby(va_arg(ap, int), data);
	else if (*str == 's')
		putstr_lobby(va_arg(ap, char *), data);
	else if (*str == 'p')
		putnbr_lobby(va_arg(ap, unsigned long long), 2, data);
	else if (*str == 'd' || *str == 'i')
		putnbr_lobby(va_arg(ap, int), -1, data);
	else if (*str == 'u')
		putnbr_lobby(va_arg(ap, unsigned int), -1, data);
	else if (*str == 'x')
		putnbr_lobby(va_arg(ap, unsigned int), 0, data);
	else if (*str == 'X')
		putnbr_lobby(va_arg(ap, unsigned int), 1, data);
	else
		putchar_lobby(*str, data);
}

int			ft_printf(const char *str, ...)
{
	t_data	data;
	va_list	ap;

	va_start(ap, str);
	init_values(&data);
	data.size = 0;
	data.index = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str = check_flags(str, &data, ap);
			check_arg(str, &data, ap);
		}
		else
			putchar_printf(*str, &data);
		if (*str != '\0')
			str++;
		init_values(&data);
	}
	va_end(ap);
	writebuffer(&data);
	return (data.size);
}
