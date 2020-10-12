/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:49:00 by sescobar          #+#    #+#             */
/*   Updated: 2020/09/03 22:04:52 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char		*ft_check_num(const char *str, t_flags *flags)
{
	if (ft_isdigit((char *)str) == 1)
	{
		(flags)->width = ft_atoi(str);
		(flags)->has_width = 1;
		while (ft_isdigit((char *)str) == 1)
			str++;
	}
	if (*str == '.')
	{
		(flags)->has_precission = 1;
		str++;
		if (ft_isdigit((char *)str) == 1)
		{
			(flags)->precission = ft_atoi(str);
			while (*str >= '0' && *str <= '9')
				str++;
		}
	}
	return (str);
}

char			*asterprec(va_list args, t_flags **flags, char *str)
{
	int	num;

	num = va_arg(args, int);
	if (num < 0)
		(*flags)->has_precission = 0;
	else
	{
		(*flags)->precission = num;
		(*flags)->has_precission = 1;
	}
	(*flags)->zero = 0;
	return (str + 1);
}

void			asterwidth(va_list args, t_flags **flags)
{
	int i;

	i = va_arg(args, int);
	if (i < 0)
	{
		(*flags)->width = -i;
		(*flags)->minus = 1;
		(*flags)->zero = 0;
	}
	else
		(*flags)->width = i;
	(*flags)->num = 1;
	(*flags)->has_width = 1;
}

const char		*ft_check_sym(const char *str, va_list args, t_flags *flags)
{
	if ((*str == '0') && (ft_is_flag((char *)str - 1) == 0))
		flags->zero = 1;
	if (*str == '-')
		(flags)->minus = 1;
	else if (*str == '+')
		(flags)->plus = 1;
	else if (*str == '0')
		(flags)->zero = 1;
	else if (*str == '#')
		(flags)->hash = 1;
	else if (*str == ' ')
		(flags)->point = 1;
	else if (*str == '.' && *(str + 1) == '*')
		str = asterprec(args, &flags, (char *)str);
	else if (*str == '*')
		asterwidth(args, &flags);
	str++;
	return (str);
}
