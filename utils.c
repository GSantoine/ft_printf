/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 08:24:02 by agras             #+#    #+#             */
/*   Updated: 2021/12/23 20:10:49 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_uint(unsigned int n, int fd)
{
	int		b_written;
	char	c;

	b_written = 0;
	if (n > 9)
		b_written = ft_putnbr_uint(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
	return (b_written + 1);
}

int	ft_putnbr_int(int n, int fd)
{
	int		b_written;
	char	c;

	b_written = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		b_written++;
		n = -n;
	}
	if (n > 9)
		b_written += ft_putnbr_int(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
	return (b_written + 1);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

ssize_t	ft_putstr(char *str)
{
	return (write(1, str, ft_strlen(str)));
}
