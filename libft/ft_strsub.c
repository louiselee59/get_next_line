/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 05:36:57 by lolee             #+#    #+#             */
/*   Updated: 2019/07/01 18:18:27 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*n;

	n = (char *)malloc(sizeof(char) * len + 1);
	if (n)
	{
		if (len == 0)
			*n = '\0';
		else
		{
			if (s && &s[start])
			{
				ft_strncpy(n, &s[start], len);
			}
			n[len] = '\0';
		}
	}
	return (n);
}
