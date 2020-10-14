/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:51:48 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/14 09:56:23 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_r1(char *spaces)
{
	ft_putstr_fd("+", 1);
	spaces[ft_strlen(spaces) - 1] = '\0';
}

int		ft_r2(char *spaces, t_flags **flags)
{
	if ((*flags)->has_precission == 1 &&
		(*flags)->precission == 0)
	{
		ft_spacer(spaces, (*flags)->width);
		return (1);
	}
	else
		return (0);
}
char	*lep(t_flags **flags, char *spaces, char *string)
{
	if ((*flags)->plus == 1 && (*flags)->has_precission == 1
		&& (*flags)->has_width == 1 && (ft_atoi(string) >= 0))
	{
		if ((*flags)->minus == 0)
			spaces[ft_strlen(spaces) - 1] = '+';
		else
			ft_r1(spaces);
	}
	return (spaces);
}

char	*ft_spaces(char *string, t_flags *flags)
{
	char	*spaces;

	(flags)->space = ((flags)->width - ft_strlen(string));
	spaces = ft_calloc(1, (size_t)(flags)->width);
	if (ft_r2(spaces, &flags) == 1)
		return (spaces);
	ft_spacer(spaces, (flags)->space);
	spaces = lep(&flags, spaces, string);
	if ((flags)->minus == 1)
	{
		spaces = ft_strjoin_free(string, spaces, 0);
		return (spaces);
	}
	if ((flags)->space < 0)
	{
		free(spaces);
		return (string);
	}
	spaces = ft_strjoin_free(spaces, string, 0);
	return (spaces);
}
