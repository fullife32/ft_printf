/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:54:25 by eassouli          #+#    #+#             */
/*   Updated: 2020/01/16 16:32:17 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "stdio.h"

int	main(void)
{
	char c = 'b';

	// SIMPLE TESTS
	ft_printf("=== SIMPLE TESTS ===\n\n");
	ft_printf("--- simple salut simple ---\n");
	ft_printf("--- char %c char ---\n", c);
	ft_printf("--- string %s %s string ---\n", "salut", NULL);
	ft_printf("--- pointer %p pointer ---\n", NULL);
	ft_printf("--- decimal d : %d d : %d i : %i u : %u decimal ---\n", 0, 10, -2147483647, 2147483647);
	ft_printf("--- hexadecimal %x %x %x %x hexadecimal ---\n", 0, 10, -2147483647, 2147483647);
	ft_printf("--- HEXADECIMAL %X %X %X %X HEXADECIMAL ---\n", 0, 10, -2147483647, 2147483647);
	ft_printf("--- percent %% percent ---\n");
	ft_printf(" => %d return size ---\n", ft_printf("--- return size salut c : %c s : %s s : %s p : %p d : %d i : %i u : %u x : %x X : %X %% : %%", c, "salut", NULL, NULL, 0, 10, -2147483647, 0, 10));
	ft_printf("\n=== WIDTH TESTS ===\n\n");
	// TESTS TAILLE DE CHAMP
	ft_printf("\nBonjour %10s %-10s, %5c%-5c\n", "Salut", "ok", 'O', 'K');
	ft_printf("%-10d et %5d", -47, 3);
	ft_printf("%s", NULL);
	return (0);
}
