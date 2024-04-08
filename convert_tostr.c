/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 08:14:21 by agras             #+#    #+#             */
/*   Updated: 2022/01/17 16:12:22 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_tostr(va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	if (!str)
	{
		return (ft_putstr("(null)"));
	}
	return (ft_putstr(str));
}
