/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_simbol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:51:07 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/09 14:06:52 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pl(char *string, int writed, t_flags *flags)
{
	string = ft_calloc(1, (size_t)(flags)->width);
	ft_spacer(string, (flags->width - 1));
	string = ft_strjoin_free(string, "%", 1);
	ft_putstr_fd(string, 1);
	writed += ft_strlen(string);
	return (writed);
}

int	pli(char *string, int writed, t_flags *flags)
{
	string = ft_calloc(1, (size_t)(flags)->width);
	ft_spacer(string, (flags->width - 1));
	string = ft_strjoin_free("%", string, 2);
	ft_putstr_fd(string, 1);
	writed += ft_strlen(string);
	return (writed);
}

int	plz(char *string, int writed, t_flags *flags)
{
	string = ft_calloc(1, (size_t)(flags)->width);
	ft_spacerc(string, (flags->width - 1));
	string = ft_strjoin_free(string, "%", 1);
	ft_putstr_fd(string, 1);
	writed += ft_strlen(string);
	return (writed);
}

int	ft_print_simbol(const char *str, int writed, t_flags **flags)
{
	char *string;

	string = NULL;
	if ((*flags)->has_width == 1 && (*flags)->minus == 1)
		writed = pli(string, writed, *flags);
	else if ((*flags)->zero == 1)
		writed = plz(string, writed, *flags);
	else if ((*flags)->has_width == 1)
		writed = pl(string, writed, *flags);
	else
	{
		ft_putstr_fd("%", 1);
		str++;
		writed++;
	}
	return (writed);
}
