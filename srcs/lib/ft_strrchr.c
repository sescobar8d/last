/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 07:22:50 by sescobar          #+#    #+#             */
/*   Updated: 2019/11/29 11:23:12 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		count;
	char	*s;

	s = (char *)str;
	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	while (count != 0)
	{
		if (str[count] == c)
		{
			return (&s[count]);
		}
		count--;
	}
	if (c == '\0')
		return (&s[count]);
	if (c == str[0])
		return (&s[0]);
	return (0);
}
