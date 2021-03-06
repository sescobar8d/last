/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:50:39 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/20 09:38:52 by sescobar         ###   ########.fr       */
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

char    *checkz(char *hex, t_flags **flags)
{
        hex = ft_strjoin_free(hex, "0x0", 1);
        if ((*flags)->has_precission == 1 && (*flags)->precission == 0)
	{
		free(hex);
		hex = ft_strjoin_free("", "", 0);
	}
	if ((*flags)->has_precission == 1)
                hex = precission_p(hex, flags);
        hex = width_p(hex, flags);
        return (hex);
}
char	*lds(unsigned long n, char *hex, t_flags *flags)
{
	if (!n)
		hex = checkz(hex, &flags);
	return (hex);
}

int			ft_print_pointer(va_list args,
		int writed, t_flags **flags)
{
	unsigned long	n;
	char			*hex;

	n = va_arg(args, unsigned long);
	hex = lds(n, (hex = ft_calloc(1, sizeof(char))), *flags);
	if (n)
	{
		free(hex);
		if ((((*flags)->has_precission == 1 && (*flags)->precission == 0) ||
		((*flags)->has_width == 1 && (*flags)->width == 0)) && (n == 0))
			hex = ft_strjoin("", "");
		else
			hex = ft_ul_to_hex(n);
		if ((*flags)->hash == 1 && (*flags)->zero == 1 && (*flags)->has_width == 1
		&& (*flags)->has_precission == 0 && ((*flags)->width > ft_strlen(hex)))
			hex = ft_strjoin_free("0", hex, 2);
		if ((*flags)->hash == 1 && n != 0)
			hex = ft_strjoin_free("0x", hex, 2);
		hex = precission_p(hex, flags);
		hex = width_p(hex, flags);
	}
	ft_putstr_fd(hex, 1);
	writed = writed + ft_strlen(hex);
	free(hex);
	return (writed);
}
