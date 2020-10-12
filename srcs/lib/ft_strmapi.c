/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 07:13:29 by sescobar          #+#    #+#             */
/*   Updated: 2019/11/29 08:53:54 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	count;
	char			*result;

	count = 0;
	if (!s)
		return (NULL);
	if (!(result = (char *)malloc(sizeof(*s) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[count])
	{
		result[count] = f(count, s[count]);
		count++;
	}
	result[count] = '\0';
	return (result);
}
