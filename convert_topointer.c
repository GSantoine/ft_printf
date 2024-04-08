/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_topointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:54:17 by agras             #+#    #+#             */
/*   Updated: 2022/01/31 19:58:09 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlong_hex(unsigned long n, int fd, char *base)
{
	int		b_written;

	b_written = 0;
	if (n > 15)
		b_written = ft_putlong_hex(n / 16, fd, base);
	write(fd, &base[n % 16], 1);
	return (b_written + 1);
}

int	convert_topointer(va_list *args)
{
	void			*p;
	unsigned long	*i;
	int				b_written;

	b_written = 0;
	p = va_arg(*args, void *);
	i = (unsigned long *)&p;
	if (*i == 0)
		return (ft_putstr("0x0"));
	write(1, "0x", 2);
	b_written += 2;
	b_written += ft_putlong_hex(*i, 1, "0123456789abcdef");
	return (b_written);
}
