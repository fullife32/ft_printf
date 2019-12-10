/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writenum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:18:42 by eassouli          #+#    #+#             */
/*   Updated: 2019/12/10 05:26:28 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intcount(unsigned long long n)
{
	int					count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	ft_itoa(long long n, t_data *data)
{
	unsigned long long	num;
	int					count;

	num = n < 0 ? -n : n;
	count = ft_intcount(num);
	if (n < 0)
		ft_putchar('-', data);
	if (num /= 10 != 0)
	{
		ft_itoa(num / 10, data);
		ft_putchar(num % 10 + '0', data);
	}
}
