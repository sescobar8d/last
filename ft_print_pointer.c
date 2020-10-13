/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:50:39 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/13 13:55:20 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*precission_p(char *hex, t_flags **flags)
{
	char	*esp;

	if ((*flags)->precission >= ft_strlen(hex) && (*flags)->precission > 0)
	{
		esp = ft_calloc((*flags)->precission - ft_strlen(hex) + 1, sizeof(char));
		ft_memset(esp, '0', (*flags)->precission - ft_strlen(hex));
		hex = ft_strjoin_free(esp, hex, 3);
	}
	hex = ft_strjoin_free("0x", hex, 2);
	return (hex);
}

char		*width_p(char *hex, t_flags **flags)
{
	char	*esp;

	if ((*flags)->width > ft_strlen(hex))
	{
		esp = ft_calloc(1, (size_t)((*flags)->width - ft_strlen(hex) + 1));
		ft_memset(esp, ' ', (*flags)->width - ft_strlen(hex));
		if ((*flags)->zero == 1 && (*flags)->has_precission == 0)
			ft_memset(esp, '0', (*flags)->width - ft_strlen(hex));
		if ((*flags)->minus == 0)
			hex = ft_strjoin_free(esp, hex, 3);
		else
			hex = ft_strjoin_free(hex, esp, 3);
	}
	return (hex);
}

int			ft_print_pointer(const char *str, va_list args,
		int writed, t_flags **flags)
{
	unsigned long	n;
	char			*hex;

	n = va_arg(args, unsigned long);
	if (!p)
		hex = ft_strjoin_free(hex, "0x0", 1);
	if ((((*flags)->has_precission == 1 && (*flags)->precission == 0) ||
		((*flags)->has_width == 1 && (*flags)->width == 0)) && (n == 0))
		hex = ft_strjoin_free("", "", 0);
	else
		hex = ft_ul_to_hex(n);
	hex = precission_p(hex, flags);
	if ((*flags)->hash == 1 && (*flags)->zero == 1 && (*flags)->has_width == 1
		&& (*flags)->has_precission == 0 && ((*flags)->width > ft_strlen(hex)))
		hex = ft_strjoin_free("0", hex, 2);
	if ((*flags)->hash == 1 && n != 0)
		hex = ft_strjoin_free("0x", hex, 2);
	hex = width_p(hex, flags);
	ft_putstr_fd(hex, 1);
	writed = writed + ft_strlen(hex);
	free(hex);
	return (writed);
}
