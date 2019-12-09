/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:54:25 by eassouli          #+#    #+#             */
/*   Updated: 2019/12/09 20:55:44 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	ft_printf("Nombre de caracteres : %d", ft_printf("%conjour%s%ld\nsalut\n%sok           %d", 'B', " toi\n", -2147483648, "it's ", 10));
	return (0);
}
