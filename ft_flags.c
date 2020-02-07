/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:30:45 by eassouli          #+#    #+#             */
/*   Updated: 2020/02/07 15:32:57 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char		*ft_check_flags(const char *str, t_data *data, va_list ap)
{
	str++;
	while (*str && ft_isarg(str) == -1)
	{
		if ((*str >= '0' && *str <= '9') || *str == '*')
			str = ft_def_width(str, data, ap);
		if (*str == '.')
			str = ft_def_precision(str, data, ap);
		if (*str == '-')
		{
			data->minus = 1;
			data->zero = 0;
		}
		if (ft_isarg(str) == -1)
			str++;
	}
	return (str);
}

const char		*ft_def_width(const char *str, t_data *data, va_list ap)
{
	if (*str == '0')
	{
		str++;
		if ((*str >= '0' && *str <= '9') || *str == '*')
			if (data->minus == 0)
				data->zero = 1;
		while (*str == '0')
			str++;
	}
	if (*str >= '0' && *str <= '9')
		data->width = ft_atoi(str);
	else if (*str == '*')
		data->width = va_arg(ap, int);
	if (data->width < 0)
	{
		data->width = -data->width;
		data->minus = 1;
		data->zero = 0;
	}
	while (*str >= '0' && *str <= '9')
		str++;
	return (str);
}

const char		*ft_def_precision(const char *str, t_data *data, va_list ap)
{
	str++;
	if (*str == '*')
		data->precision = va_arg(ap, int);
	else
	{
		data->precision = ft_atoi(str);
		while (*str >= '0' && *str <= '9')
			str++;
	}
	if (data->precision < 0)
		data->precision = -1;
	return (str);
}
