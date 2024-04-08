/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_touint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:37:09 by agras             #+#    #+#             */
/*   Updated: 2021/12/23 20:10:53 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_touint(va_list *args)
{
	unsigned int	i;

	i = va_arg(*args, unsigned int);
	return (ft_putnbr_uint(i, 1));
}
