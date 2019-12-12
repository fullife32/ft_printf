/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:17:49 by eassouli          #+#    #+#             */
/*   Updated: 2019/12/12 14:43:39 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_values(t_data *data)
{
	data->index = 0;
	data->size = 0;
	data->width = 0;
	data->precision = 0;
}

int	ft_printf(const char *str, ...)
{
	t_data	*data;
	va_list	ap;
	int		i;

	if (!(data = malloc(sizeof(t_data))))
		return (ft_error(&data));
	va_start(ap, str);
	i = 0;
	ft_init_values(data);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (str[i] == 'c')
				ft_putchar(va_arg(ap, int), data);
			else if (str[i] == 's')
				ft_putstr(va_arg(ap, char *), data);
			else if (str[i] == 'p')
				ft_putstr("", data);
			else if (str[i] == 'd' || str[i] == 'i' || str[i] == 'u')
				ft_putnbr(va_arg(ap, int), data);
			else if (str[i] == 'x')
				ft_putstr("", data);
			else if (str[i] == 'X')
				ft_putstr("", data);
			else if (str[i] == '%')
				ft_putchar(str[i], data);
		}
		else
			ft_putchar(*str, data);
		if (*str != '\0')
			str++;
		
	}
	va_end(ap);
	ft_writebuffer(data);
	i = data->size;
	free(data);
	return (i);
}
