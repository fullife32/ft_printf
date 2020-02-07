/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writechars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:40:22 by eassouli          #+#    #+#             */
/*   Updated: 2020/02/07 15:28:50 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_lobby(int c, t_data *data)
{
	if (data->zero == 1)
		ft_putzerospaces(data->width - 1, '0', data);
	else if (data->width != 0 && data->minus != 1)
		ft_putzerospaces(data->width - 1, ' ', data);
	ft_putchar(c, data);
	if (data->width != 0 && data->minus == 1)
		ft_putzerospaces(data->width - 1, ' ', data);
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
	int	width;

	if (s == NULL)
		s = "(null)";
	if (data->precision != -1 && data->precision < (int)ft_strlen(s))
		width = data->width - data->precision;
	else
		width = data->width - ft_strlen(s);
	if (data->zero == 1)
		ft_putzerospaces(width, '0', data);
	if (data->width != 0 && data->minus != 1)
		ft_putzerospaces(width, ' ', data);
	ft_putstr2(s, data);
	if (data->width != 0 && data->minus == 1)
		ft_putzerospaces(width, ' ', data);
}

void	ft_putstr2(char *s, t_data *data)
{
	while (s != NULL && *s && data->precision != 0)
	{
		ft_putchar(*s++, data);
		data->precision--;
	}
}

void	ft_putzerospaces(int len, char c, t_data *data)
{
	if (c == ' ' || data->zero == 1)
		data->width = 0;
	if (c == '0' && data->zero == 0)
		data->precision = -1;
	while (len-- > 0)
		ft_putchar(c, data);
}
