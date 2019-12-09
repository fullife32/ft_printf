/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writenum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:18:42 by eassouli          #+#    #+#             */
/*   Updated: 2019/12/09 20:56:33 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intcount(unsigned int n)
{
	int				count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int		ft_itoa(int n, t_data *data)
{
	unsigned int	num;
	int				count;
	char			*nb;

	num = n < 0 ? -n : n;
	count = (n <= 0) ? ft_intcount(num) + 1 : ft_intcount(num);
	if (!(nb = malloc(sizeof(char) * (count + 1))))
		return (ft_error(&data));
	nb[count] = '\0';
	while (count-- != 0)
	{
		nb[count] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		nb[0] = '-';
	ft_putstr(nb, data);
	free(nb);
	return (0);
}
