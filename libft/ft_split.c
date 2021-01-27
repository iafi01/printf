/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:55:05 by liafigli          #+#    #+#             */
/*   Updated: 2021/01/20 14:01:32 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(const char *str, char c)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			i++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (i);
}

static char		*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	i = 0;
	j = 0;
	index = -1;
	if (!s)
		return (0);
	if (!(split = malloc((count_words(s, c) + 1) * sizeof(char *))))
		return (0);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((((s[i] == c || i == ft_strlen(s)) && index >= 0)))
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
