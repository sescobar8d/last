/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:06:11 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/12 15:49:24 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int		ft_lenint(long n)
{
	int	count;

	count = 1;
	if (n < 0)
		n = n * (-1);
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

void	ft_aux(int *len, int *neg, long int *nb)
{
	*len = *len + 1;
	*neg = 1;
	*nb = *nb * (-1);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			neg;
	int			len;
	long int	nb;

	neg = 0;
	nb = n;
	len = ft_lenint(n) + 1;
	if (n < 0)
		ft_aux(&len, &neg, &nb);
	if (!(result = malloc(len)))
		return (0);
	result[len - 1] = '\0';
	if (nb == 0)
		result[len - 2] = nb + 48;
	while (nb)
	{
		result[len - 2] = (nb % 10) + 48;
		nb = nb / 10;
		len--;
	}
	if (neg == 1)
		result[len - 2] = '-';
	return (result);
}*/

static char	*ft_strnew(int i)
{
	char	*str;

	if (!(str = malloc(i * sizeof(char))))
		return (0);
	else
		return (str);
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
