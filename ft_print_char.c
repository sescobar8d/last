/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:50:27 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/12 11:47:06 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fpr(char ch, int writed)
{
	ft_putchar_fd(ch, 1);
	writed++;
	return (writed);
}

int		ft_print_char(va_list args, int writed, t_flags **flags)
{
	char	ch;
	char	*r;

	ch = va_arg(args, int);
	r = ft_calloc(1, (size_t)((*flags)->width));
	if ((*flags)->minus == 1)
	{
		writed = ft_minus(ch, r, writed, *flags);
		free(r);
		return (writed);
	}
	if ((*flags)->has_width == 1)
	{
		ft_spacer(r, ((*flags)->width) - 1);
		ft_putstr_fd(r, 1);
		writed = writed + ft_strlen(r);
		ft_putchar_fd(ch, 1);
		writed++;
	}
	else
		writed = fpr(ch, writed);
	free(r);
	return (writed);
}

int		ft_minus(char c, char *str, int writed, t_flags *flags)
{
	ft_putchar_fd(c, 1);
	writed++;
	ft_spacer(str, ((flags)->width - 1));
	ft_putstr_fd(str, 1);
	writed = writed + ft_strlen(str);
	return (writed);
}
