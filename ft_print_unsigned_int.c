/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:51:26 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/12 19:56:09 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_p2(char *r, t_flags **flags)
{
	if ((*flags)->has_precission == 1 && (*flags)->has_width == 1)
	{
		r = ft_spacerz((char *)r, (*flags)->precission, *flags);
		r = ft_spaces((char *)r, *flags);
		(*flags)->has_precission = 0;
		(*flags)->has_width = 0;
		return (r);
	}
	else
		return (r);
}

char	*ft_l2(char *r, t_flags **flags)
{
	if ((*flags)->zero == 1)
		r = ft_spacerz((char *)r, (*flags)->width, *flags);
	if ((*flags)->has_width == 1 && (*flags)->zero == 0)
		r = ft_spaces((char*)r, *flags);
	if ((*flags)->has_precission == 1)
		r = ft_spacerz((char *)r, (*flags)->precission, *flags);
	return (r);
}

char	*ft_p1(char *r, t_flags *flags)
{
	r = ft_p2(r, &flags);
	return (r);
}

char	*ft_l1(char *r, t_flags *flags)
{
	r = ft_l2(r, &flags);
	return (r);
}

int		ft_print_unsigned_int(va_list args, int writed, t_flags **flags)
{
	unsigned int	number;
	char			*r;

	number = va_arg(args, unsigned int);
	if (number == 4294967295 || number == (unsigned int)-8000 ||
			number == 2147483648)
	{
		ft_putmui_fd(number, 1);
		writed = writed + 10;
		return (writed);
	}
	//r = /*ft_p1((ft_itoa(number))*/"hola"/*, *flags)*/;
	//r = ft_l1(r, *flags);
	r = ft_l1(ft_p1((ft_itoa(number)), *flags), *flags);
	if ((*flags)->precission == 0 && (*flags)->has_precission == 1)
	{
		ft_putstr_fd("", 1);
		free(r);
		return (writed);
	}
	ft_putstr_fd(r, 1);
	writed += ft_strlen(r);
	free(r);
	return (writed);
}
