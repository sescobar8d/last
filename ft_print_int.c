/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:50:47 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/12 13:20:26 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_f2(char *r, int number, t_flags **flags)
{
	if ((*flags)->point == 1 && (*flags)->plus == 0
		&& number >= 0 && (*flags)->width > 0)
		(*flags)->width = (*flags)->width - 1;
	if ((*flags)->has_precission == 1 && (*flags)->has_width == 1)
	{
		r = ft_spacerz((char *)r, (*flags)->precission, *flags);
		r = ft_spaces((char *)r, *flags);
		if ((*flags)->plus == 0)
			(*flags)->has_precission = 0;
		(*flags)->has_width = 0;
	}
	if ((*flags)->plus == 1 && (number >= 0) &&
		(*flags)->has_precission == 0 && (*flags)->zero == 0
		&& (*flags)->minus == 0)
		r = ft_strjoin_free("+", r, 2);
	if ((*flags)->zero == 1 && (*flags)->minus == 0)
		r = ft_spacerz((char *)r, (*flags)->width, *flags);
	if ((*flags)->has_precission == 1 && (*flags)->plus == 1
		&& (number >= 0) && (*flags)->width < ft_strlen(ft_itoa(number))
		&& (*flags)->minus == 0)
		ft_putstr_fd("+", 1);
	if ((*flags)->has_width == 1 && (*flags)->zero == 0)
		r = ft_spaces((char *)r, *flags);
	return (r);
}

char	*ft_f1(char *r, int number, t_flags *flags)
{
	r = ft_f2(r, number, &flags);
	return (r);
}

char	*ft_h1(char *r, t_flags *flags)
{
	if ((flags)->has_precission == 1 && (flags)->precission == 0
		&& (flags)->width > 0)
	{
		if ((flags)->minus == 0)
			r[(flags)->width - 1] = '+';
		else
			*r = '+';
	}
	return (r);
}

int		ft_print_int(va_list args, int writed, t_flags **flags)
{
	int		number;
	char	*r;
	char	*t;

	number = va_arg(args, int);
	r = ft_itoa(number);
	t = ft_strjoin_free(r, "", 1);
	/*r = ft_f1(r, number, *flags);
	if ((*flags)->has_precission == 1 && (*flags)->precission == 0
		&& (*flags)->width == 0)
	{
		ft_putstr_fd("", 1);
		return (writed);
	}
	r = ft_h1(r, *flags);
	if ((*flags)->has_precission == 1)
		r = ft_spacerz((char *)r, (*flags)->precission, *flags);
	if ((*flags)->point == 1 && number >= 0 && (*flags)->plus == 0)
		ft_putstr_fd(" ", 1);
	if ((*flags)->hash == 1)
		writed = writed + 1;
	ft_putstr_fd(r, 1);
	writed += ft_strlen(r);
	*/free(t);
	return (writed);
}
