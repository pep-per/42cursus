/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 00:31:37 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/11/16 21:25:21 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	remove_left_set(char const *s1, char const *set, size_t *new_len, \
							size_t len)
{
	size_t	i;

	*new_len = len;
	i = 0;
	while (is_set(s1[i], set))
	{
		*new_len -= 1;
		i++;
	}
}

static void	remove_right_set(char const *s1, char const *set, size_t *new_len, \
							size_t len)
{
	size_t	i;

	if (*new_len == 0)
		return ;
	i = len - 1;
	while (is_set(s1[i], set))
	{
		*new_len -= 1;
		i--;
	}
}

static void	copy_new_str(char const *s1, char const *set, char *new, \
						size_t new_len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (is_set(s1[i], set))
		i++;
	if (!is_set(s1[i], set) && s1[i])
	{
		while (s1[i] && j < new_len)
		{
			new[j] = (char)s1[i];
			j++;
			i++;
		}
	}
	new[j] = 0;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	len;
	size_t	new_len;

	if (*s1 == 0 || *set == 0)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	remove_left_set(s1, set, &new_len, len);
	remove_right_set(s1, set, &new_len, len);
	new = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!new)
		return (0);
	copy_new_str(s1, set, new, new_len);
	return (new);
}
