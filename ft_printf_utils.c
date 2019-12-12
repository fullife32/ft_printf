/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:22:08 by eassouli          #+#    #+#             */
/*   Updated: 2019/12/11 23:09:19 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_error(t_data **data)
{
	if (*data)
		free(*data);
	*data = NULL;
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[++i] != '\0')
		;
	return (i);
}
