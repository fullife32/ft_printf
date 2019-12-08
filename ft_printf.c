/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:17:49 by eassouli          #+#    #+#             */
/*   Updated: 2019/12/08 20:31:20 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_data	*data;
	int		i;

	va_start(ap, str);
	if (!(data = malloc(sizeof(t_data))))
		return (ft_error(&data));
	i = 0;
	data->n = 0;
	ft_cleanbuffer(data);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
				ft_putchar(va_arg(ap, int), data);
			else if (str[i] == 's')
				ft_putstr(va_arg(ap, char *), data);
			else if (str[i] == 'd' || str[i] == 'i')
				if (ft_itoa(va_arg(ap, int), data) == -1)
					return (ft_error(&data));
		}
		else
			ft_putchar(str[i], data);
		if (str[i] != '\0')
			i++;
	}
	va_end(ap);
	ft_writebuffer(data);
	i = data->n;
	free(data);
	return (i);
}
