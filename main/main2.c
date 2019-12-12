/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:48:49 by eassouli          #+#    #+#             */
/*   Updated: 2019/12/11 23:09:35 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("salut\n");
	printf("%conjour%s%ld\nsalut\n%sok           %d", 'B', " toi\n", -2147483648, "it's ", 10);
	printf("\n%%     \n");
	printf("salut%d\n", -922337);
	printf("%d", printf("salut%d\n", 184467));
	return (0);
}
