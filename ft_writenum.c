/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writenum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:18:42 by eassouli          #+#    #+#             */
/*   Updated: 2019/12/30 20:47:48 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long long n, t_data *data)
{
	unsigned long long	num;
	int					count;

	num = n < 0 ? -n : n;
	count = ft_intcount(num);
	if (n < 0)
		ft_putchar('-', data);
	if (num /= 10 != 0)
	{
		ft_putnbr(num / 10, data);
		ft_putchar(num % 10 + '0', data);
	}
}

void	ft_putnbr_base(long long n, int up, t_data *data)
{
	unsigned long long	num;

	num = n < 0 ? -n : n;
	if (n < 0)
		ft_putchar('-', data);
	if (up == 2 && (up = 0) == 0)
		ft_putstr("0x", data);
	if (num /= 16 != 0)
	{
		ft_putnbr_base(num / 16, up, data);
		if (up == 1)
			ft_putchar(HEXA_UPP[num % 16], data);
		else
			ft_putchar(HEXA_LOW[num % 16], data);
	}
}
