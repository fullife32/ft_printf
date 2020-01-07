/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:17:49 by eassouli          #+#    #+#             */
/*   Updated: 2020/01/07 15:31:01 by eassouli         ###   ########.fr       */
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

char	*ft_check_flags(const char *str, t_data *data)
{
	if (*str == '-')
		data->minus = 1;
	return (str);
}

int	ft_printf(const char *str, ...)
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
			if (*str == 'c')
				ft_putchar(va_arg(ap, int), &data);
			else if (*str == 's')
				ft_putstr(va_arg(ap, char *), &data);
			else if (*str == 'p')
				ft_putnbr_basep(va_arg(ap, long long), 1, &data);
			else if (*str == 'd' || *str == 'i' || *str == 'u')
				ft_putnbr(va_arg(ap, int), &data);
			else if (*str == 'x')
				ft_putnbr_basex(va_arg(ap, int), 0, &data);
			else if (*str == 'X')
				ft_putnbr_basex(va_arg(ap, int), 1, &data);
			else if (*str == '%')
				ft_putchar(*str, &data);
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
