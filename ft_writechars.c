/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writechars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:40:22 by eassouli          #+#    #+#             */
/*   Updated: 2019/12/10 05:17:45 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, t_data *data)
{
	if (data->i == BUFFER_SIZE)
		ft_writebuffer(data);
	data->buffer[data->i] = c;
	data->i++;
}

void	ft_putstr(char *s, t_data *data)
{
	ft_strtobuffer(s, data);
}
