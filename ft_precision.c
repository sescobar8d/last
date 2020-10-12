/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:50:00 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/12 10:52:54 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin_free(char *str1, char *str2, int i)
{
	char	*temp;

	temp = ft_strjoin(str1, str2);
	if (i == 1)
		free(str1);
	else if (i == 2)
		free(str2);
	if (i == 3)
	{
		free(str1);
		free(str2);
	}
	return (temp);
}

char	*ft_precision(char *string, t_flags *flags)
{
	char	*result;

	if ((flags)->has_precission == 1 &&
		(flags)->precission == 0)
		string = "";
	if ((flags)->precission > ft_strlen(string))
		return (string);
	result = ft_calloc(1, (flags)->precission);
	ft_strlcat(result, string, (flags)->precission + 1);
	return (result);
}
