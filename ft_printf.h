/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:01:06 by eassouli          #+#    #+#             */
/*   Updated: 2020/01/14 16:25:37 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFFER_SIZE 128
# define HEXA_LOW "0123456789abcdef"
# define HEXA_UPP "0123456789ABCDEF"

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
	int		minus;
	int		zero;
	char	buffer[BUFFER_SIZE + 1];
}				t_data;

size_t			ft_strlen(const char *s);
int				ft_intcount(unsigned long long n);
void			ft_putnbr_lobby(long long n, t_data *data);
void			ft_putnbr(long long n, t_data *data);
void			ft_putnbr_basep(long long n, int up, t_data *data);
void			ft_putnbr_basex(int n, int up, t_data *data);
int				ft_atoi(const char *str);
void			ft_putchar_lobby(int c, t_data *data);
void			ft_putchar(int c, t_data *data);
void			ft_putstr_lobby(char *s, t_data *data);
void			ft_putstr2(char *s, t_data *data);
void			ft_putspaces(int len, t_data *data);
void			ft_writebuffer(t_data *data);
int				ft_printf(const char *str, ...);

#endif
