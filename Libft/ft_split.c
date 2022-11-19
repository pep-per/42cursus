/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 04:01:04 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/11/19 23:28:58 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	count_word(char const *s, char c, size_t *word_count)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			*word_count += 1;
		while (s[i] != c && s[i])
			i++;
	}
}

static size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	free_word(char **words, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static int	duplicate_word(char const *s, size_t len, char **words, \
							size_t count)
{
	char	*word;
	size_t	i;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
	{
		free_word(words, count);
		return (0);
	}
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	words[count] = word;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	word_count;
	size_t	i;

	word_count = 0;
	count_word(s, c, &word_count);
	words = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (0);
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			if (!duplicate_word(s, word_len(s, c), words, i))
				return (0);
			i++;
		}
		while (*s != c && *s)
			s++;
	}
	words[i] = 0;
	return (words);
}
