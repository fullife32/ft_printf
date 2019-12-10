/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:54:25 by eassouli          #+#    #+#             */
/*   Updated: 2019/12/10 18:38:03 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	main(void)
{
	ft_printf("salut\n");
	ft_printf("%conjour%s%d\nsalut\n%sok           %d", 'B', " toi\n", -2147483648, "it's ", 10);
	ft_printf("\n%%     \n");
	ft_printf("salut%ll\n", -9223372036854775807);
	ft_printf("%d", ft_printf("salut%ld\n", 1844674407370955161));
	return (0);
}
