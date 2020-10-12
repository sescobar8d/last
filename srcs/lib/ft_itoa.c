/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:06:11 by sescobar          #+#    #+#             */
/*   Updated: 2019/11/26 14:28:45 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lenint(long n)
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
}
