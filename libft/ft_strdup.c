/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahmed <bahmed@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 07:36:28 by bahmed            #+#    #+#             */
/*   Updated: 2025/05/23 07:36:30 by bahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1) + 1;
	s2 = malloc(len * sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, len);
	return (s2);
}
