/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:50:00 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/06 12:34:38 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
