/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 07:41:39 by sescobar          #+#    #+#             */
/*   Updated: 2019/11/29 08:44:28 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_len(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

int				ft_countwords(char *str, char lim)
{
	int	result;
	int	count;

	count = 0;
	result = 0;
	if (!str)
		return (0);
	while (str[count] && str[count] == lim)
		count++;
	while (str[count])
	{
		while (str[count] && str[count] != lim)
			count++;
		result++;
		while (str[count] && str[count] == lim)
			count++;
	}
	return (result);
}

static char		*next_word(char const *s, char c)
{
	if (!s)
		return (0);
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static void		cleanup(char **split, size_t cut)
{
	size_t	count;

	count = 0;
	while (count < cut)
	{
		free(split[count]);
		count++;
	}
	free(split);
}

char			**ft_split(char const *s, char c)
{
	char	**split;
	size_t	cut;
	size_t	wordcount;

	wordcount = ft_countwords((char *)s, c);
	if (!(split = (char **)malloc((wordcount + 1) * sizeof(char *))))
		return (0);
	if (split == NULL || !s)
		return (NULL);
	cut = 0;
	while (cut < wordcount)
	{
		s = next_word(s, c);
		split[cut] = ft_substr(s, 0, word_len(s, c));
		if (split[cut] == NULL)
		{
			cleanup(split, cut);
			return (NULL);
		}
		cut++;
		s += word_len(s, c);
	}
	split[wordcount] = NULL;
	return (split);
}
