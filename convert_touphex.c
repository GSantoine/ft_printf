/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_touphex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:33:04 by agras             #+#    #+#             */
/*   Updated: 2021/12/23 20:10:52 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_touphex(va_list *args)
{
	unsigned int	i;

	i = va_arg(*args, unsigned int);
	return (ft_putnbr_hex(i, 1, "0123456789abcdef"));
}
