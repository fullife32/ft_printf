/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:48:49 by eassouli          #+#    #+#             */
/*   Updated: 2020/01/15 19:07:22 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char c = 'b';

	// TESTS SIMPLES
	printf("=== SIMPLE TESTS ===\n\n");
	printf("--- simple salut simple ---\n");
	printf("--- char %c char ---\n", c);
	printf("--- string %s %s string ---\n", "salut", NULL);
	printf("--- pointer %p pointer ---\n", NULL);
	printf("--- decimal %d %d %i %u decimal ---\n", 0, 10, -2147483647, 2147483647);
	printf("--- hexadecimal %x %x %x %x hexadecimal ---\n", 0, 10, -2147483647, 2147483647);
	printf("--- HEXADECIMAL %X %X %X %X HEXADECIMAL ---\n", 0, 10, -2147483647, 2147483647);
	printf("--- percent %% percent ---\n");
	printf(" %d Return size ---\n", printf("--- Return size salut %c %s %s %p %d %i %u %x %X %%", c, "salut", NULL, NULL, 0, 10, -2147483647, 0, 10));
	printf("\n=== WIDTH TESTS ===\n\n");
	// TESTS TAILLE DE CHAMP
	printf("\nBonjour %10s %-10s, %5c%-5c\n", "Salut", "ok", 'O', 'K');
	printf("%-10d et %5d", -47, 3);
	printf("%s", NULL);
	return (0);
}
