/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:17:49 by eassouli          #+#    #+#             */
/*   Updated: 2020/01/09 17:36:48 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_values(t_data *data)
{
	data->index = -1;
	data->size = -1;
	data->width = -1;
	data->precision = -1;
	data->minus = -1;
	data->zero = -1;
}

int		ft_isarg(char *str)
{
	if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd' || *str == 'i'
	|| *str == 'u' || *str == 'x' || *str == 'X' || *str == '%')
		return (1);
	return (-1);
}

char	*ft_check_flags(char *str, t_data *data)
{
	while (*str && ft_isarg(str) == -1)
	{
		if (*str == '-')
			data->minus = 1;
	}
	return (str);
}

void	ft_check_arg(const char *str, t_data *data, va_list ap)
{
	if (*str == 'c')
		ft_putchar(va_arg(ap, int), data);
	else if (*str == 's')
		ft_putstr(va_arg(ap, char *), data);
	else if (*str == 'p')
		ft_putnbr_basep(va_arg(ap, long long), 1, data);
	else if (*str == 'd' || *str == 'i' || *str == 'u')
		ft_putnbr(va_arg(ap, int), data);
	else if (*str == 'x')
		ft_putnbr_basex(va_arg(ap, int), 0, data);
	else if (*str == 'X')
		ft_putnbr_basex(va_arg(ap, int), 1, data);
	else if (*str == '%')
		ft_putchar(*str, data);
}

int		ft_printf(const char *str, ...)
{
	t_data	data;
	va_list	ap;
	int		i;

	va_start(ap, str);
	ft_init_values(&data);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			str = ft_check_flags(str, &data);
			ft_check_arg(str, &data, ap);
		}
		else
			ft_putchar(*str, &data);
		if (*str != '\0')
			str++;
	}
	va_end(ap);
	ft_writebuffer(&data);
	i = data.size;
	return (i);
}
