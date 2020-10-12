/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 07:54:01 by sescobar          #+#    #+#             */
/*   Updated: 2019/11/29 11:22:20 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		count;
	char	*s;

	s = (char *)str;
	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] == c)
		{
			return (&s[count]);
		}
		count++;
	}
	if (c == '\0')
		return (&s[count]);
	return (0);
}
