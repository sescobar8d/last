/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:46:24 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/06 12:42:01 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t		count;
	unsigned char	*s;

	count = 0;
	s = (unsigned char *)str;
	while (count < n)
	{
		s[count] = 0;
		count++;
	}
}
