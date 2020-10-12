/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:13:00 by sescobar          #+#    #+#             */
/*   Updated: 2019/11/28 14:12:23 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	size_t i;

	if (!*find)
		return ((char *)str);
	i = ft_strlen((char *)find);
	while (*str && n-- >= i)
	{
		if (*str == *find && !ft_strncmp(str, find, i))
			return ((char *)str);
		str++;
	}
	return (NULL);
}
