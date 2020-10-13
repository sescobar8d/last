/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:50:56 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/13 13:28:22 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precission_pointer(char *hex, t_flags **flags)
{
	char	*esp;

	if ((*flags)->precission >= ft_strlen(hex) && (*flags)->precission > 0)
	{
		esp = ft_calloc(1, (*flags)->precission - ft_strlen(hex) + 1);
		ft_memset(esp, '0', (*flags)->precission - ft_strlen(hex));
		hex = ft_strjoin_free(esp, hex, 3);
	}
	hex = ft_strjoin_free("0x", hex, 2);
	free(esp);
	return (hex);
}

char	*ft_width_pointer(char *hex, t_flags **flags)
{
	char	*esp;

	if ((*flags)->width > ft_strlen(hex))
	{
		esp = ft_calloc(1, (size_t)((*flags)->width - ft_strlen(hex) + 1));
		ft_memset(esp, ((*flags)->zero == 1 ? '0' : ' '),
			(*flags)->width - ft_strlen(hex));
		if ((*flags)->minus == 0)
			hex = ft_strjoin_free(esp, hex, 3);
		else
			hex = ft_strjoin_free(hex, esp, 3);
	}
	return (hex);
}

char	*checkz(char *hex, t_flags *flags)
{
	hex = ft_strjoin_free(hex, "0x0", 1);
	if (flags->has_precission == 1 && flags->precission == 0)
		hex = ft_strjoin_free("", "", 0);
	if ((flags)->has_precission == 1)
		hex = ft_precission_pointer(hex, &flags);
	hex = ft_width_pointer(hex, &flags);
	return (hex);
}

int		ft_print_pointer(va_list args, int writed, t_flags **flags)
{
	unsigned long	p;
	char			*hex;

	p = va_arg(args, unsigned long);
	hex = ft_calloc(1, (size_t)(*flags)->width);
	if (!p)
		hex = checkz(hex, *flags);
	else
	{
		if ((((*flags)->has_precission == 1 && (*flags)->precission == 0) ||
			((*flags)->has_width == 1 && (*flags)->width == 0)) && (p == 0))
			hex = ft_strjoin_free("", "", 0);
		else
			hex = ft_ul_to_hex(p);
		hex = ft_precission_pointer(hex, flags);
		hex = ft_width_pointer(hex, flags);
	}
	ft_putstr_fd(hex, 1);
	writed = writed + ft_strlen(hex);
	free(hex);
	return (writed);
}
