/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:27:01 by sescobar          #+#    #+#             */
/*   Updated: 2019/11/29 09:31:01 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*result;
	int		count;
	int		len;

	count = 0;
	if (!s1)
		return (0);
	result = malloc(sizeof(char));
	while (s1[count] != '\0' && ft_strchr(set, s1[count]) != NULL)
		count++;
	if (s1[count] == '\0')
	{
		result[0] = '\0';
		return (result);
	}
	len = ft_strlen(&s1[count]);
	while (ft_strchr(set, s1[count + len - 1]) != NULL)
		len--;
	if (!(result = malloc(len + 1)))
		return (0);
	ft_memcpy(result, &s1[count], len);
	result[len] = '\0';
	return (result);
}
