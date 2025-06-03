/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahmed <bahmed@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 07:37:28 by bahmed            #+#    #+#             */
/*   Updated: 2025/05/23 07:37:29 by bahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char			*p;
	unsigned char	ch;
	size_t			offset;

	ch = c;
	offset = ft_strlen(str);
	p = (char *)str + offset;
	if (ch == '\0')
		return (p);
	while (p >= str)
	{
		if (*p == ch)
			return (p);
		p--;
	}
	return (NULL);
}
