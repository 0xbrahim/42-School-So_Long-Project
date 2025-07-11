/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahmed <bahmed@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 07:36:04 by bahmed            #+#    #+#             */
/*   Updated: 2025/05/23 07:36:06 by bahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static size_t	ft_word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**ft_clear(char **lst, int i)
{
	while (i--)
		free(lst[i]);
	free(lst);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**lst;
	int		i;
	size_t	word_len;

	lst = malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			word_len = ft_word_len(s, c);
			lst[i] = ft_substr(s, 0, word_len);
			if (!lst[i])
				return (ft_clear(lst, i));
			s += word_len;
			i++;
		}
	}
	lst[i] = NULL;
	return (lst);
}
