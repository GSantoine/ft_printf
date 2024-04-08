/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:28:29 by agras             #+#    #+#             */
/*   Updated: 2021/12/23 20:14:15 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

# define NB_CONVERS 8

typedef struct s_converts {
	int		(*convert)(va_list *args);
	char	id;
	int		size;
}	t_converts;

// UTILS

int		print_byte(char c);
size_t	ft_strlen(char *str);
ssize_t	ft_putstr(char *str);
int		ft_putnbr_int(int n, int fd);
int		ft_putnbr_uint(unsigned int n, int fd);
int		ft_putnbr_hex(unsigned int n, int fd, char *base);

// CONVERSIONS

int		convert_tochar(va_list *args);
int		convert_tostr(va_list *args);
int		convert_toint(va_list *args);
int		convert_touint(va_list *args);
int		convert_touphex(va_list *args);
int		convert_tolowhex(va_list *args);
int		convert_topointer(va_list *args);

int		ft_printf(const char *format, ...);

#endif