/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writenum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:18:42 by eassouli          #+#    #+#             */
/*   Updated: 2020/02/10 09:44:54 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnbr_lobby(long long n, int up, t_data *data)
{
	int	count;

	count = width_size(n, up, data);
	if (data->width != 0 && data->minus != 1)
		if (!(data->zero == 1 && data->precision == -1))
			putzerospaces(data->width - count, ' ', data);
	if (up == -1)
		if (!(n == 0 && data->precision == 0))
			putnbr_printf(n, data);
	if (up == 0 || up == 1)
		if (!(n == 0 && data->precision == 0))
			putnbr_basex(n, up, data);
	if (up == 2)
		putnbr_basep(n, up, data);
	if (data->width != 0 && data->minus == 1 && data->zero == 0)
		putzerospaces(data->width - count, ' ', data);
}

int		width_size(long long n, int up, t_data *data)
{
	int	count;

	if (up == -1)
	{
		count = n < 0 ? intcount(-n, 10) + 1 : intcount(n, 10);
		if (data->precision >= count)
			count = n < 0 ? data->precision + 1 : data->precision;
		if (data->precision == 0 && n == 0)
			count--;
	}
	else
	{
		count = intcount(n, 16);
		if (data->precision >= count)
			count = data->precision;
		if (data->precision == 0 && n == 0)
			count--;
	}
	count = up == 2 ? count + 2 : count;
	return (count);
}

void	putnbr_printf(long long n, t_data *data)
{
	unsigned long long	num;
	int					count;

	num = n < 0 ? -n : n;
	if (n < 0)
		putchar_printf('-', data);
	if (data->precision != -1)
	{
		putzerospaces(data->precision - intcount(num, 10), '0', data);
		data->precision = -1;
	}
	if (data->zero == 1)
	{
		count = n < 0 ? intcount(num, 10) + 1 : intcount(num, 10);
		putzerospaces(data->width - count, '0', data);
		data->width = 0;
	}
	if (num > 9)
		putnbr_printf(num / 10, data);
	putchar_printf(num % 10 + '0', data);
}

void	putnbr_basex(unsigned int n, int up, t_data *data)
{
	if (data->precision != -1)
	{
		putzerospaces(data->precision - intcount(n, 16), '0', data);
		data->precision = -1;
	}
	if (data->zero == 1)
		putzerospaces(data->width - intcount(n, 16), '0', data);
	if (n >= 16)
		putnbr_basex(n / 16, up, data);
	if (up == 1)
		putchar_printf(HEXA_UPP[n % 16], data);
	else
		putchar_printf(HEXA_LOW[n % 16], data);
}

void	putnbr_basep(long long n, int up, t_data *data)
{
	unsigned long long		num;

	num = n < 0 ? -n : n;
	if (up == 2 && (up = 3))
	{
		if (data->precision != -1)
			data->precision += 2;
		putstr_printf("0x", data);
	}
	if (!(n == 0 && data->precision == 0))
	{
		if (data->precision != -1)
		{
			putzerospaces(data->precision - intcount(num, 16), '0', data);
			data->precision = -1;
		}
		if (data->zero == 1)
			putzerospaces(data->width - intcount(num, 16), '0', data);
		if (num >= 16)
			putnbr_basep(num / 16, up, data);
		putchar_printf(HEXA_LOW[num % 16], data);
	}
}
