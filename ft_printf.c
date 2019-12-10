/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:17:49 by eassouli          #+#    #+#             */
/*   Updated: 2019/12/10 05:18:49 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_data	*data;
	va_list	ap;
	int		i;

	if (!(data = malloc(sizeof(t_data))))
		return (ft_error(&data));
	va_start(ap, str);
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
			else if (str[i] == 'p')
				ft_putstr("ceci n'a pas encore ete fait alors fait le flag p", data);
			else if (str[i] == 'd' || str[i] == 'i' || str[i] == 'u')
				ft_itoa(va_arg(ap, int), data);
			else if (str[i] == 'x')
				ft_putstr("ceci n'a pas encore ete fait alors fait le flag x", data);
			else if (str[i] == 'X')
				ft_putstr("ceci n'a pas encore ete fait alors fait le flag X", data);
			else if (str[i] == '%')
				ft_putchar(str[i], data);
			else if (str[i++] == 'l')
			{
				if (str[i] == 'l')
					ft_itoa(va_arg(ap, long long), data);
				else
					ft_itoa(va_arg(ap, long), data);	
			}
			else if (str[i++] == 'h')
			{
				if (str[i] == 'h')
					ft_putchar(va_arg(ap, int), data);
				else
					ft_putchar(va_arg(ap, int), data);
			}
		}
		else
				ft_putchar(str[i], data);
		if (str[i] != '\0')
			i++;
		data->width = 0;
		data->precision = 0;
	}
	va_end(ap);
	ft_writebuffer(data);
	i = data->n;
	free(data);
	return (i);
}
