/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tolowhex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:47:54 by agras             #+#    #+#             */
/*   Updated: 2021/12/23 22:40:43 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_tolowhex(va_list *args)
{
	int	i;

	i = va_arg(*args, int);
	return (ft_putnbr_hex(i, 1, "0123456789ABCDEF"));
}
