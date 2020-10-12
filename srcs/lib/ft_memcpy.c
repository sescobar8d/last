/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:45:56 by sescobar          #+#    #+#             */
/*   Updated: 2019/11/21 12:03:36 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			countsrc;
	size_t			countdst;
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	countsrc = 0;
	countdst = 0;
	if (!dst && !src && n > 0)
		return (0);
	while (countsrc < n)
	{
		d[countdst] = s[countsrc];
		countsrc++;
		countdst++;
	}
	return (dst);
}
