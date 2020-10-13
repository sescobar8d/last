/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:06:11 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/13 13:04:05 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strnew(int i)
{
	char	*str;
	char	*temp;

	if (!(str = malloc(i * sizeof(char))))
		return (0);
	else
	{
		temp = ft_strjoin(str, "");
		free(str);
		return (temp);
	}
}

static	int	ft_intlen(unsigned int n)
{
	if (n < 10)
		return (1);
	else
		return (ft_intlen(n / 10) + 1);
}

char		*ft_itoa(int nbr)
{
	char			*s;
	int				len;
	unsigned int	n;

	if (nbr < 0)
		n = -nbr;
	else
		n = nbr;
	len = ft_intlen(n);
	if (nbr < 0)
		len++;
	s = ft_strnew(len + 1);
	if (!s)
		return (0);
	s[len] = '\0';
	if (nbr < 0)
		s[0] = '-';
	while (((nbr < 0) ? 1 : 0) < len)
	{
		s[len - 1] = n % 10 + '0';
		len--;
		n /= 10;
	}
	return (s);
}
