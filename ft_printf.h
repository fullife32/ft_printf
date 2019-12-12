/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:01:06 by eassouli          #+#    #+#             */
/*   Updated: 2019/12/12 14:43:23 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFFER_SIZE 128

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_data
{
	int		index;
	int		size;
	int		width;
	int		precision;
	char	buffer[BUFFER_SIZE + 1];
}				t_data;

int				ft_error(t_data **data);
size_t			ft_strlen(const char *s);
int				ft_intcount(unsigned long long n);
void			ft_putnbr(long long n, t_data *data);
void			ft_putchar(int c, t_data *data);
void			ft_putstr(char *s, t_data *data);
void			ft_strtobuffer(char *s, t_data *data);
void			ft_writebuffer(t_data *data);
int				ft_printf(const char *str, ...);

#endif
