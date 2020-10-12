/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 07:02:27 by sescobar          #+#    #+#             */
/*   Updated: 2019/11/28 14:20:35 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;

	if (!(result = malloc(ft_strlen(s1) + 1)))
		return (0);
	if (*result == '\0')
		return (0);
	ft_strcpy(result, s1);
	return (result);
}
