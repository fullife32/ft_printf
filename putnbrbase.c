/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:34:01 by eassouli          #+#    #+#             */
/*   Updated: 2019/12/12 16:08:56 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

int					is_alphanum(char *str, unsigned int i)
{
	if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9'))
		return (1);
	return (0);
}

int					ft_strcmp_base(char *base, unsigned int i)
{
	unsigned int	j;

	j = i + 1;
	while (base[i] != '\0' && base[j] != '\0')
	{
		if (base[i] == base[j])
			return (1);
		j++;
	}
	return (0);
}

unsigned int		ft_baselen(char *base, unsigned int baselen)
{
	while (base[baselen] != '\0')
	{
		if (is_alphanum(base, baselen) == 0
				|| ft_strcmp_base(base, baselen) != 0)
			return (0);
		baselen++;
	}
	return (baselen);
}

void				ft_putnbr_base(int nbr, char *base)
{
	unsigned int	baselen;
	unsigned int	unb;

	baselen = 0;
	baselen = ft_baselen(base, baselen);
	if (baselen <= 1)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		unb = nbr * -1;
	}
	else
		unb = nbr;
	if (unb >= baselen)
	{
		ft_putnbr_base((unb / baselen), base);
		ft_putchar(base[unb % baselen]);
	}
	else
		ft_putchar(base[unb % baselen]);
}
