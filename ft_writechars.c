/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writechars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:40:22 by eassouli          #+#    #+#             */
/*   Updated: 2019/12/08 20:04:14 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_data *data)
{
	data->buffer[data->i] = c;
	data->i++;
	data->n++;
	if (data->i == BUFFER_SIZE)
			ft_writebuffer(data);
}

void	ft_putstr(char *s, t_data *data)
{
	ft_strtobuffer(s, data);
}
