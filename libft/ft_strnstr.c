/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahmed <bahmed@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 07:37:22 by bahmed            #+#    #+#             */
/*   Updated: 2025/05/23 07:37:24 by bahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	s2len;
	size_t	i;
	size_t	j;

	s2len = ft_strlen(s2);
	if (s2len == 0)
		return ((char *)s1);
	i = 0;
	while (i < n && s1[i] != '\0')
	{
		j = 0;
		while ((i + j) < n && s1[i + j] != '\0' && s2[j] != '\0' && s1[i
				+ j] == s2[j])
			j++;
		if (j == s2len)
			return ((char *)(s1 + i));
		i++;
	}
	return (0);
}
