/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:58:57 by agras             #+#    #+#             */
/*   Updated: 2022/01/25 11:41:01 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int n, int fd, char *base)
{
	int		b_written;

	b_written = 0;
	if (n > 15)
		b_written = ft_putnbr_hex(n / 16, fd, base);
	write(fd, &base[n % 16], 1);
	return (b_written + 1);
}
