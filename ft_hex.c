/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:49:34 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/16 11:07:21 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_num_to_hex(int n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	else if (n == 10)
		return ('a');
	else if (n == 11)
		return ('b');
	else if (n == 12)
		return ('c');
	else if (n == 13)
		return ('d');
	else if (n == 14)
		return ('e');
	else if (n == 15)
		return ('f');
	return (0);
}

char	*ft_str_inv(char *str)
{
	int		l;
	int		count;
	char	sust;

	l = ft_strlen(str);
	count = 0;
	while (count < l)
	{
		sust = str[count];
		str[count] = str[l - 1];
		str[l - 1] = sust;
		count++;
		l--;
	}
	return (str);
}

char	*ft_ui_to_hex(unsigned int n)
{
	char			*hex;
	unsigned int	rest;
	int				count;

	count = 0;
	hex = ft_calloc(50, sizeof(char));
	if (n == 0)
	{
		hex[count] = '0';
		count++;
	}
	while (n != 0)
	{
		rest = n % 16;
		n /= 16;
		hex[count] = (ft_num_to_hex(rest));
		count++;
	}
	hex[count] = '\0';
	ft_str_inv(hex);
	return (hex);
}

char	*ft_ul_to_hex(unsigned long n)
{
	char			*hex;
	unsigned long	rest;
	int				count;

	count = 0;
	hex = ft_calloc(50, sizeof(char));
	if (n == 0)
		hex[count] = '0';
	while (n != 0)
	{
		rest = n % 16;
		n /= 16;
		hex[count] = (ft_num_to_hex(rest));
		count++;
	}
	hex[count] = '\0';
	ft_str_inv(hex);
	return (hex);
}

char	*ft_str_dup(const char *s1)
{
	char	*result;
	if (!(result = malloc(ft_strlen(s1) + 1)))
		return (0);
	if (*result == '\0')
		return (0);
	ft_strcpy(result, s1);
	return (result);
}
