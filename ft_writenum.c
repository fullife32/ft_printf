/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writenum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:18:42 by eassouli          #+#    #+#             */
/*   Updated: 2020/01/29 18:34:46 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_lobby(long long n, int up, t_data *data)
{
	int		count;

	if (up == -1)
	{
		count = n < 0 ? ft_intcount(-n, 10) + 1 : ft_intcount(n, 10);
		if (data->precision > count)
			count = data->precision;
	}
	else
	{
		count = n < 0 ? ft_intcount(-n, 16) + 1 : ft_intcount(n, 16);
		if (data->precision > count)
			count = data->precision;
	}
	count = up == 2 ? count + 2 : count;
	if (data->width != 0 && data->minus != 1)
		if (!(data->zero == 1 && data->precision == -1))
			ft_putzerospaces(data->width - count, ' ', data);
	if (up == -1)
		if (!(n == 0 && data->precision == 0))
			ft_putnbr(n, data);
	if (up == 0 || up == 1)
		if (!(n == 0 && data->precision == 0))
			ft_putnbr_basexp((int)n, up, data);
	if (up == 2)
		if (!(data->zero == 1 && data->precision == -1))
			ft_putnbr_basexp(n, up, data);
	if (data->width != 0 && data->minus == 1 && data->zero == 0)
		ft_putzerospaces(data->width - count, ' ', data);
}

void	ft_putnbr(long long n, t_data *data)
{
	unsigned long long	num;
	int					count;

	num = n < 0 ? -n : n;
	if (n < 0)
		ft_putchar('-', data);
	if (data->precision != -1)
	{
		ft_putzerospaces(data->precision - ft_intcount(num, 10), '0', data);
		data->precision = -1;
	}
	if (data->zero == 1)
	{
		count = n < 0 ? ft_intcount(num, 10) + 1 : ft_intcount(num, 10);
		ft_putzerospaces(data->width - count, '0', data);
		data->width = 0;
	}
	if (num > 9)
		ft_putnbr(num / 10, data);
	ft_putchar(num % 10 + '0', data);
}

void	ft_putnbr_basexp(long long n, int up, t_data *data)
{
	unsigned long long		num;
	unsigned int			numx;

	if (up == 2 || up == 3)
		num = n < 0 ? -n : n;
	else
	{
		numx = n;
		num = numx;
	}
	if (data->precision != -1)
	{
		ft_putzerospaces(data->precision - ft_intcount(num, 16), '0', data);
		data->precision = -1;
	}
	if (data->zero == 1)
		ft_putzerospaces(data->width - ft_intcount(num, 16), '0', data);
	if (up == 2 && (up = 3))
		ft_putstr2("0x", data);
	if (num >= 16)
	{
		ft_putnbr_basexp(num / 16, up, data);
		if (up == 1)
			ft_putchar(HEXA_UPP[num % 16], data);
		else
			ft_putchar(HEXA_LOW[num % 16], data);
	}
	else if (up == 1)
		ft_putchar(HEXA_UPP[num % 16], data);
	else
		ft_putchar(HEXA_LOW[num % 16], data);
}
