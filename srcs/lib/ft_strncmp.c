/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 08:04:50 by sescobar          #+#    #+#             */
/*   Updated: 2019/11/21 12:05:06 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t count;

	count = 0;
	while ((str1[count] != '\0' && str2[count] != '\0')
			&& str1[count] == str2[count] && count < n)
	{
		if (str1[count] != str2[count])
			return ((unsigned char)str1[count] - (unsigned char)str2[count]);
		count++;
	}
	if (count == n)
		return (0);
	return ((unsigned char)str1[count] - (unsigned char)str2[count]);
}
