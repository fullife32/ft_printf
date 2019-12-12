/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:32:03 by eassouli          #+#    #+#             */
/*   Updated: 2019/12/11 23:01:10 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strtobuffer(char *s, t_data *data)
{
	while (*s)
	{
		if (data->i == BUFFER_SIZE)
			ft_writebuffer(data);
		data->buffer[data->i] = *s++;
		data->i++;
	}
}

void	ft_writebuffer(t_data *data)
{
	write(1, &data->buffer, data->i);
	data->n += data->i;
	data->i = 0;
}
