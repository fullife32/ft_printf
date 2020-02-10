/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writechars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:40:22 by eassouli          #+#    #+#             */
/*   Updated: 2020/02/10 14:54:54 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putchar_lobby(int c, t_data *data)
{
	if (data->zero == 1)
		putzerospaces(data->width - 1, '0', data);
	else if (data->width != 0 && data->minus != 1)
		putzerospaces(data->width - 1, ' ', data);
	putchar_printf(c, data);
	if (data->width != 0 && data->minus == 1)
		putzerospaces(data->width - 1, ' ', data);
}

void	putchar_printf(int c, t_data *data)
{
	if (data->index == BUFFER_SIZE)
		writebuffer(data);
	data->buffer[data->index] = c;
	data->index++;
}

void	putstr_lobby(char *s, t_data *data)
{
	int	width;

	if (s == NULL)
		s = "(null)";
	if (data->precision != -1 && data->precision < (int)ft_strlen(s))
		width = data->width - data->precision;
	else
		width = data->width - ft_strlen(s);
	if (data->zero == 1)
		putzerospaces(width, '0', data);
	if (data->width != 0 && data->minus != 1)
		putzerospaces(width, ' ', data);
	putstr_printf(s, data);
	if (data->width != 0 && data->minus == 1)
		putzerospaces(width, ' ', data);
}

void	putstr_printf(char *s, t_data *data)
{
	while (s != NULL && *s && data->precision != 0)
	{
		putchar_printf(*s++, data);
		data->precision--;
	}
}

void	putzerospaces(int len, char c, t_data *data)
{
	if (c == ' ' || data->zero == 1)
		data->width = 0;
	if (c == '0' && data->zero == 0)
		data->precision = -1;
	while (len-- > 0)
		putchar_printf(c, data);
}
