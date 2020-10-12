/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 08:33:46 by sescobar          #+#    #+#             */
/*   Updated: 2019/11/28 08:14:01 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	count;

	count = 0;
	result = malloc(sizeof(char));
	if (!s || len == 0 || start > len)
	{
		result[0] = '\0';
		return (result);
	}
	if (!(result = malloc(len * sizeof(char) + 1)))
		return (result);
	while (count < len)
	{
		result[count] = s[count + start];
		count++;
	}
	result[count] = '\0';
	return (result);
}
