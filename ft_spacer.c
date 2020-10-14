/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spacer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:51:39 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/14 11:07:23 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_spacer(void *str, int n)
{
	int		count;
	char	*s;

	s = (char *)str;
	count = 0;
	while (count < n)
	{
		s[count] = 32;
		count++;
	}
}

void	ft_spacerc(void *str, int n)
{
	int		count;
	char	*s;

	s = (char *)str;
	count = 0;
	while (count < n)
	{
		s[count] = '0';
		count++;
	}
}

int		ft_sp(int c, t_flags **flags)
{
	if ((*flags)->zero == 1 && (*flags)->plus == 1 && (*flags)->has_width == 1
		&& (*flags)->has_precission == 0)
	{
		ft_putstr_fd("+", 1);
		c = 1;
		return (c);
	}
	else
		return (c);
}

int		ft_yui(int c, t_flags **flags)
{
	ft_putstr_fd("-", 1);
	(*flags)->hash = 1;
	if ((*flags)->zero == 1)
		c = 1;
	return (c);
}

char	*ft_spacerz(char *str, int n, t_flags *flags)
{
	char	*result;
	int		c;

	c = 0;
	result = ft_calloc(1, (size_t)n);
	c = ft_sp(c, &flags);
	if (*str == '-')
	{
		str++;
		if ((flags)->has_precission == 1 && (flags)->has_width == 1)
		{
			ft_spacerc(result, ((n - c) - ft_strlen(str)));
			result = ft_strjoin_free((ft_strjoin_free("-", result, 2)), str, 3);
			return (result);
		}
		c = ft_yui(c, &flags);
	}
	if (ft_strlen(str) > (unsigned int)n)
	{
		//free(result);
		return (str);
	}
	ft_spacerc(result, ((n - c) - ft_strlen(str)));
	result = ft_strjoin_free(result, str, 0);
	return (result);
}

