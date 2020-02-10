/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:01:06 by eassouli          #+#    #+#             */
/*   Updated: 2020/02/10 09:45:00 by eassouli         ###   ########.fr       */
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

void			init_values(t_data *data);
int				isarg(const char *str);
void			check_arg(const char *str, t_data *data, va_list ap);
int				ft_printf(const char *str, ...);

const char		*check_flags(const char *str, t_data *data, va_list ap);
const char		*def_width(const char *str, t_data *data, va_list ap);
const char		*def_precision(const char *str, t_data *data, va_list ap);

size_t			ft_strlen(const char *s);
int				intcount(unsigned long long n, int base);
int				atoi_printf(const char *str);
void			writebuffer(t_data *data);

void			putchar_lobby(int c, t_data *data);
void			putchar_printf(int c, t_data *data);
void			putstr_lobby(char *s, t_data *data);
void			putstr_printf(char *s, t_data *data);
void			putzerospaces(int len, char c, t_data *data);

void			putnbr_lobby(long long n, int up, t_data *data);
int				width_size(long long n, int up, t_data *data);
void			putnbr_printf(long long n, t_data *data);
void			putnbr_basex(unsigned int n, int up, t_data *data);
void			putnbr_basep(long long n, int up, t_data *data);

#endif
