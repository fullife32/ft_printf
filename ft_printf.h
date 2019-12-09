/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:01:06 by eassouli          #+#    #+#             */
/*   Updated: 2019/12/09 21:04:45 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFFER_SIZE 64

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_data
{
	int		i;
	int		n;
	char	buffer[BUFFER_SIZE];
}				t_data;

typedef struct	s_flag
{
	int		precision;
	int		padding;
}				t_flag;

int				ft_error(t_data **data);
size_t			ft_strlen(const char *s);
int				ft_intcount(unsigned int n);
int				ft_itoa(int n, t_data *data);
void			ft_putchar(char c, t_data *data);
void			ft_putstr(char *s, t_data *data);
void			ft_strtobuffer(char *s, t_data *data);
void			ft_writebuffer(t_data *data);
void			ft_cleanbuffer(t_data *data);
int				ft_printf(const char *str, ...);

#endif
