/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:51:16 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/12 11:59:51 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		long_condition(t_flags *flags)
{
	if (((flags)->width > 0 && (flags)->precission > 0 &&
		(flags)->precission < ft_strlen("null"))
		|| ((flags)->has_width == 0 &&
		(flags)->has_precission == 1 &&
		(flags)->precission < ft_strlen("null")))
		return (1);
	else
		return (0);
}

void	ft_delete(t_flags *flags)
{
	flags->has_width = 0;
	flags->has_precission = 0;
}

char	*ld2(char *string, t_flags **flags)
{
	if ((*flags)->has_width == 1 && (*flags)->zero == 0)
		string = ft_spaces((char *)string, *flags);
	else if ((*flags)->has_precission == 1)
		string = ft_precision((char *)string, *flags);
	else if ((*flags)->zero == 1 && (*flags)->minus == 0)
		string = ft_spacerz(string, (*flags)->width, *flags);
	else if ((*flags)->zero == 1 && (*flags)->minus == 1)
		string = ft_spaces(string, *flags);
	return (string);
}

char	*ld(char *string, t_flags *flags)
{
	string = ld2(string, &flags);
	return (string);
}

int		ft_print_str(va_list args, int writed, t_flags **flags)
{
	char	*rec;
	char	*string;

	rec = va_arg(args, char *);
	string = ft_calloc(1, (size_t)(*flags)->width);
	string = rec;
	if (string == NULL)
	{
		string = "(null)";
		if ((*flags)->has_precission == 1 && (*flags)->precission > 0)
			string = ft_precision((char *)string, *flags);
		string = ft_spaces(string, *flags);
	}
	else if ((*flags)->has_width == 1 && (*flags)->has_precission == 1)
	{
		string = ft_precision((char *)string, *flags);
		string = ft_spaces((char *)string, *flags);
		ft_delete(*flags);
	}
	string = ld(string, *flags);
	ft_putstr_fd(string, 1);
	writed += ft_strlen(string);
	return (writed);
}
