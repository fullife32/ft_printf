/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:32:03 by eassouli          #+#    #+#             */
/*   Updated: 2019/12/11 18:48:49 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strtobuffer(char *s, t_data *data)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (data->i == BUFFER_SIZE)
			ft_writebuffer(data);
		data->buffer[data->i] = s[i];
		data->i++;
		i++;
	}
}

void	ft_writebuffer(t_data *data)
{
	write(1, &data->buffer, data->i);
	data->n += data->i;
	ft_cleanbuffer(data);
}

void	ft_cleanbuffer(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->i)
	{
		data->buffer[i] = 0;
		i++;
	}
	data->i = 0;
}
