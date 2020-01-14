/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:54:25 by eassouli          #+#    #+#             */
/*   Updated: 2020/01/14 15:47:57 by eassouli         ###   ########.fr       */
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
	ft_printf("\nBonjour %10s %-10s, %5c%-5c\n", "Salut", "ok", 'O', 'K');
	ft_printf("%-10d et %5d", -47, 3);
	return (0);
}
