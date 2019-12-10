/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:48:49 by eassouli          #+#    #+#             */
/*   Updated: 2019/12/10 05:43:57 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	printf("salut\n");
	printf("%conjour%s%ld\nsalut\n%sok           %d", 'B', " toi\n", -2147483648, "it's ", 10);
	printf("\n%%     \n");
	printf("salut%ld\n", -9223372036854775807);
	printf("%d", printf("salut%ld\n", 1844674407370955161));
	return (0);
}
