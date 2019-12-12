/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:32:03 by eassouli          #+#    #+#             */
/*   Updated: 2019/12/12 13:31:32 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strtobuffer(char *s, t_data *data)
{
	while (*s)
	{
		if (data->index == BUFFER_SIZE)
			ft_writebuffer(data);
		data->buffer[data->index] = *s++;
		data->index++;
	}
}

void	ft_writebuffer(t_data *data)
{
	write(1, &data->buffer, data->index);
	data->size += data->index;
	data->index = 0;
}
