/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:17:49 by eassouli          #+#    #+#             */
/*   Updated: 2020/02/07 15:31:10 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_init_values(t_data *data)
{
	data->width = 0;
	data->precision = -1;
	data->minus = 0;
	data->zero = 0;
}

int			ft_isarg(const char *str)
{
	if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd' || *str == 'i'
	|| *str == 'u' || *str == 'x' || *str == 'X' || *str == '%')
		return (1);
	return (-1);
}

void		ft_check_arg(const char *str, t_data *data, va_list ap)
{
	if (*str == 'c')
		ft_putchar_lobby(va_arg(ap, int), data);
	else if (*str == 's')
		ft_putstr_lobby(va_arg(ap, char *), data);
	else if (*str == 'p')
		ft_putnbr_lobby(va_arg(ap, long long), 2, data);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr_lobby(va_arg(ap, int), -1, data);
	else if (*str == 'u')
		ft_putnbr_lobby(va_arg(ap, unsigned int), -1, data);
	else if (*str == 'x')
		ft_putnbr_lobby(va_arg(ap, int), 0, data);
	else if (*str == 'X')
		ft_putnbr_lobby(va_arg(ap, int), 1, data);
	else if (*str == '%')
		ft_putchar_lobby(*str, data);
}

int			ft_printf(const char *str, ...)
{
	t_data	data;
	va_list	ap;

	va_start(ap, str);
	ft_init_values(&data);
	data.size = 0;
	data.index = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str = ft_check_flags(str, &data, ap);
			ft_check_arg(str, &data, ap);
		}
		else
			ft_putchar(*str, &data);
		if (*str != '\0')
			str++;
		ft_init_values(&data);
	}
	va_end(ap);
	ft_writebuffer(&data);
	return (data.size);
}
