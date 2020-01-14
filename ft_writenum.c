/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writenum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:18:42 by eassouli          #+#    #+#             */
/*   Updated: 2020/01/14 16:34:45 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_lobby(long long n, t_data *data)
{
	int	count;

	count = n < 0 ? ft_intcount(-n) + 1 : ft_intcount(n);
	if (data->width != -1 && data->minus != 1)
		ft_putspaces(data->width - count, data);
	ft_putnbr(n, data);
	if (data->width != -1 && data->minus == 1)
		ft_putspaces(data->width - count, data);
}

void	ft_putnbr(long long n, t_data *data)
{
	unsigned long long	num;

	num = n < 0 ? -n : n;
	if (n < 0)
		ft_putchar('-', data);
	if (num > 9)
		ft_putnbr(num / 10, data);
	ft_putchar(num % 10 + '0', data);
}

void	ft_putnbr_basep(long long n, int up, t_data *data)
{
	unsigned long long	num;

	num = n < 0 ? -n : n;
	if (up == 1 && !(up = 0))
		ft_putstr2("0x", data);
	if (num >= 16)
	{
		ft_putnbr_basep(num / 16, up, data);
		ft_putchar(HEXA_LOW[num % 16], data);
	}
	else
		ft_putchar(HEXA_LOW[num % 16], data);
}

void	ft_putnbr_basex(int n, int up, t_data *data)
{
	unsigned int	num;

	num = n;
	if (num >= 16)
	{
		ft_putnbr_basex(num / 16, up, data);
		if (up == 1)
			ft_putchar(HEXA_UPP[num % 16], data);
		else
			ft_putchar(HEXA_LOW[num % 16], data);
	}
	else if (up == 1)
		ft_putchar(HEXA_UPP[num % 16], data);
	else if (up == 0)
		ft_putchar(HEXA_LOW[num % 16], data);
}

int		ft_atoi(const char *str)
{
	int		i;
	long	nb;
	int		sign;

	i = 0;
	nb = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb < 0)
			return (sign == 1 ? -1 : 0);
		i++;
	}
	return (sign * nb);
}
