/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:51:16 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/20 11:47:18 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_delete(t_flags *flags)
{
	flags->has_width = 0;
	flags->has_precission = 0;
}

char	*ld2(char *string, t_flags **flags)
{
	if ((*flags)->has_width == 1 && (*flags)->zero == 0)
		string = ft_spaces_str((char *)string, *flags);
	else if ((*flags)->has_precission == 1)
		string = ft_precision_str((char *)string, *flags);
	else if ((*flags)->zero == 1 && (*flags)->minus == 0)
		string = ft_spacerz_str(string, (*flags)->width, *flags);
	else if ((*flags)->zero == 1 && (*flags)->minus == 1)
		string = ft_spaces_str(string, *flags);
	return (string);
}

char	*ld(char *string, t_flags *flags)
{
	string = ld2(string, &flags);
	return (string);
}

int		ft_print_str(va_list args, int writed, t_flags **flags)
{
	char	*string;

	string = va_arg(args, char *);
	if (string == NULL)
	{
		string = "(null)";
		if ((*flags)->has_precission == 1 && (*flags)->precission > 0)
			string = ft_precision_str((char *)string, *flags);
		string = ft_spaces_str(string, *flags);
	}
	else if ((*flags)->has_width == 1 && (*flags)->has_precission == 1)
	{
		string = ft_precision_str((char *)string, *flags);
		string = ft_spaces_str((char *)string, *flags);
		ft_delete(*flags);
	}
	string = ld(string, *flags);
	ft_putstr_fd(string, 1);
	writed += ft_strlen(string);
	if ((*flags)->precission != 0 && (*flags)->has_width == 0)
		free(string);
	return (writed);
}
