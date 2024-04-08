/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:24:20 by agras             #+#    #+#             */
/*   Updated: 2022/01/31 19:42:11 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_byte(char c)
{
	write(1, &c, 1);
	return (1);
}

t_converts	*build_conv_arr_2(t_converts *conversions)
{
	conversions[5].convert = convert_touphex;
	conversions[5].id = 'x';
	conversions[5].size = sizeof(unsigned int);
	conversions[6].convert = convert_tolowhex;
	conversions[6].id = 'X';
	conversions[6].size = sizeof(unsigned int);
	conversions[7].convert = convert_topointer;
	conversions[7].id = 'p';
	conversions[7].size = sizeof(void *);
	return (conversions);
}

t_converts	*build_conv_arr(void)
{
	t_converts	*conversions;

	conversions = malloc(sizeof(t_converts) * NB_CONVERS);
	if (!conversions)
		return (NULL);
	conversions[0].convert = convert_tochar;
	conversions[0].id = 'c';
	conversions[0].size = sizeof(char);
	conversions[1].convert = convert_tostr;
	conversions[1].id = 's';
	conversions[1].size = sizeof(char *);
	conversions[2].convert = convert_toint;
	conversions[2].id = 'i';
	conversions[2].size = sizeof(int);
	conversions[3].convert = convert_toint;
	conversions[3].id = 'd';
	conversions[3].size = sizeof(int);
	conversions[4].convert = convert_touint;
	conversions[4].id = 'u';
	conversions[4].size = sizeof(unsigned int);
	return (build_conv_arr_2(conversions));
}

int	check_identifier(t_converts *conversions, char id, va_list *args)
{
	int	i;

	i = 0;
	if (id == '%')
		return (print_byte('%'));
	while (i < NB_CONVERS)
	{
		if (id == conversions[i].id)
			return (conversions[i].convert(args));
		i++;
	}
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			b_written;
	t_converts	*conversions;

	conversions = build_conv_arr();
	if (!conversions)
		return (-1);
	va_start(args, format);
	b_written = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			b_written += check_identifier(conversions, *format, &args);
		}
		else
			b_written += print_byte(*format);
		format++;
	}
	free(conversions);
	return (b_written);
}
