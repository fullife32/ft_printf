/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:01:06 by eassouli          #+#    #+#             */
/*   Updated: 2020/01/29 18:12:13 by eassouli         ###   ########.fr       */
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

void			ft_init_values(t_data *data);
int				ft_isarg(const char *str);
const char		*ft_check_flags(const char *str, t_data *data, va_list ap);
void			ft_check_arg(const char *str, t_data *data, va_list ap);
int				ft_printf(const char *str, ...);

size_t			ft_strlen(const char *s);
int				ft_intcount(unsigned long long n, int base);
int				ft_atoi(const char *str);
void			ft_writebuffer(t_data *data);

void			ft_putchar_lobby(int c, t_data *data);
void			ft_putchar(int c, t_data *data);
void			ft_putstr_lobby(char *s, t_data *data);
void			ft_putstr2(char *s, t_data *data);
void			ft_putzerospaces(int len, char c, t_data *data);

void			ft_putnbr_lobby(long long n, int up, t_data *data);
void			ft_putnbr(long long n, t_data *data);
void			ft_putnbr_basexp(long long n, int up, t_data *data);

#endif
