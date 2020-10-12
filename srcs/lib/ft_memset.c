/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:25 by sescobar          #+#    #+#             */
/*   Updated: 2019/11/21 12:03:56 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			count;
	unsigned char	*s;

	s = (unsigned char *)str;
	count = 0;
	while (count < len)
	{
		s[count] = (unsigned char)c;
		count++;
	}
	return (str);
}
