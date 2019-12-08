/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:32:03 by eassouli          #+#    #+#             */
/*   Updated: 2019/12/08 20:15:27 by eassouli         ###   ########.fr       */
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
		data->buffer[data->i++] = s[i++];
		data->n++;
	}
}

void	ft_writebuffer(t_data *data)
{
	int	i;

	i = 0;
	write(1, &data->buffer, data->i);
	ft_cleanbuffer(data);
}

void	ft_cleanbuffer(t_data *data)
{
	int	i;

	i = 0;
	data->i = 0;
	while (i <= BUFFER_SIZE)
	{
		data->buffer[i] = 0;
		i++;
	}
}