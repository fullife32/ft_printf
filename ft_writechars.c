/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writechars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:40:22 by eassouli          #+#    #+#             */
/*   Updated: 2020/01/14 16:25:42 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_lobby(int c, t_data *data)
{
	if (data->width != -1 && data->minus != 1)
		ft_putspaces(data->width - 1, data);
	ft_putchar(c, data);
	if (data->width != -1 && data->minus == 1)
		ft_putspaces(data->width - 1, data);
}

void	ft_putchar(int c, t_data *data)
{
	if (data->index == BUFFER_SIZE)
		ft_writebuffer(data);
	data->buffer[data->index] = c;
	data->index++;
}

void	ft_putstr_lobby(char *s, t_data *data)
{
	if (data->width != -1 && data->minus != 1)
		ft_putspaces(data->width - ft_strlen(s), data);
	ft_putstr2(s, data);
	if (data->width != -1 && data->minus == 1)
		ft_putspaces(data->width - ft_strlen(s), data);
}

void	ft_putstr2(char *s, t_data *data)
{
	while (*s)
	{
		if (data->index == BUFFER_SIZE)
			ft_writebuffer(data);
		data->buffer[data->index] = *s++;
		data->index++;
	}
}

void	ft_putspaces(int len, t_data *data)
{
	data->width = -1;
	data->minus = -1;
	while (len-- > 0)
		ft_putchar(' ', data);
}