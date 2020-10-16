/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 09:52:38 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/16 14:47:37 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	int		count;

	count = 0;
	if (!s1 || !s2)
		return (0);
	if (!(result = malloc((ft_strlen(s1) + 1) + (ft_strlen(s2) + 1))))
		return (0);
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	count = ft_strlen(result);
	ft_strlcat(&result[count], s2, ft_strlen(s2) + 1);
	result[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (result);
}
