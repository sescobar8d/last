/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:27:11 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/12 10:03:58 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	initialize_struct(t_flags *flags)
{
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->zero = 0;
	flags->hash = 0;
	flags->num = 0;
	flags->point = 0;
	flags->has_precission = 0;
	flags->precission = 0;
	flags->has_width = 0;
	flags->width = 0;
}

int			ft_print_type(char *str, va_list args,
		int writed, t_flags *flags)
{
	/*if (*str == 's')
		writed = ft_print_str(args, writed, &flags);
	else if (*str == 'i' || *str == 'd')
		writed = ft_print_int(args, writed, &flags);
	else */if (*str == 'c')
		writed = ft_print_char(args, writed, &flags);
	str = NULL;
		/*else if (*str == '%')
		writed = ft_print_simbol(str, writed, &flags);
	else if (*str == 'u')
		writed = ft_print_unsigned_int(args, writed, &flags);
	else if (*str == 'p')
		writed = ft_print_pointer(args, writed, &flags);
	else if (*str == 'x' || *str == 'X')
		writed = ft_print_hex(str, args, writed, &flags);
	*/return (writed);
}

int			ft_is_flag(char *str)
{
	if (*str == '-' || *str == '+' || *str == ' ' ||
		(*str == '.' && *(str + 1) == '*') ||
		*str == '0' || *str == '#' || *str == '*')
		return (1);
	return (0);
}

char		*rec(char *str, int *writed)
{
	write(1, str, 1);
	str++;
	(*writed)++;
	return (str);
}

int			ft_printf(const char *str, ...)
{
	va_list	args;
	t_flags	flags;
	int		writed;

	writed = 0;
	va_start(args, str);
	while (str && *str != '\0')
		if (*str == '%')
		{
			initialize_struct(&flags);
			str++;
			while (ft_is_flag((char *)str) == 1)
				str = (char *)ft_check_sym((char *)str, args, &flags);
			if (*str == '.' || (*str >= '0' && *str <= '9'))
				str = (char *)ft_check_num((char *)str, &flags);
			writed = ft_print_type((char *)str, args, writed, &flags);
			if (*str != '\0')
				str++;
		}
		else
			str = rec((char *)str, &writed);
	va_end(args);
	return (writed);
}
