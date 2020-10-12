/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:16:09 by sescobar          #+#    #+#             */
/*   Updated: 2019/12/03 13:19:39 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				count;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	count = 0;
	if (!d && !s)
		return (0);
	if (s < d)
		while (++count <= len)
			d[len - count] = s[len - count];
	else
		while (len-- > 0)
			*(d++) = *(s++);
	return (dst);
}
