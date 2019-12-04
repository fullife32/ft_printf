/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:17:49 by eassouli          #+#    #+#             */
/*   Updated: 2019/12/03 14:41:26 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *s, t_data *link)
{
	int	i;

	i = ft_strlen(s);
	write(1, s, i);
	link->rv += i;
}

void	ft_putchar(char c, t_data *link)
{
	write(1, &c, 1);
	link->rv += 1;
}

static int	ft_intcount(unsigned int n)
{
	int count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int		ft_itoa(int n, t_data *link)
{
	unsigned int	num;
	int				count;
	char			*nb;

	num = n < 0 ? -n : n;
	count = (n <= 0) ? ft_intcount(num) + 1 : ft_intcount(num);
	if (!(nb = malloc(sizeof(char) * (count + 1))))
		return (-1);
	nb[count] = '\0';
	while (count-- != 0)
	{
		nb[count] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		nb[0] = '-';
	ft_putstr(nb, link);
	free(nb);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_data	*link;
	int		i;

	va_start(ap, str);
	if (!(link = malloc(sizeof(t_data))))
		return (-1);
	i = 0;
	link->rv = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
				ft_putchar(va_arg(ap, int), link);
			else if (str[i] == 's')
				ft_putstr(va_arg(ap, char *), link);
			else if (str[i] == 'd' || str[i] == 'i')
				if (ft_itoa(va_arg(ap, int), link) == -1)
					return (-1);
		}
		else if (str[i] != '%')
		{
			write(1, &str[i], 1);
			link->rv++;
		}
		i++;
	}
	va_end(ap);
	i = link->rv;
	free(link);
	return (i);
}