/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:54:25 by eassouli          #+#    #+#             */
/*   Updated: 2019/12/31 12:15:30 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	main(void)
{
	ft_printf("salut\n");
	ft_printf("%conjour%s%d\nsalut\n%sok           %d", 'B', " toi\n", -2147483648, "it's ", 10);
	ft_printf("\n%%     \n");
	ft_printf("salut%d\n", -922337);
	ft_printf("%d", ft_printf("salut%d\n", 184467));
	ft_printf("%x et %X et %x", 123456, -1234567890, 0);
	ft_printf(" <- %d", ft_printf("\n%p", NULL));
	return (0);
}
