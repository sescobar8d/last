/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:30:07 by sescobar          #+#    #+#             */
/*   Updated: 2020/02/26 10:20:27 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_spacing(const char c)
{
	if (c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_negative(const char c)
{
	if (c == '-')
		return (1);
	if (c == '+')
		return (2);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	count;
	int number;
	int signo;

	count = 0;
	number = 0;
	while (str[count] != '\0' && ft_spacing(str[count]) == 1)
		count++;
	signo = ft_negative(str[count]);
	if (signo == 1 || signo == 2)
		count++;
	while (str[count] != '\0' && str[count] >= '0' && str[count] <= '9')
	{
		number = (number * 10) + str[count] - '0';
		count++;
	}
	if (signo == 1)
		number = number * (-1);
	return (number);
}
