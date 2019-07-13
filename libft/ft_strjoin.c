/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 05:51:05 by lolee             #+#    #+#             */
/*   Updated: 2019/07/02 16:35:31 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*n;
	int		i;
	size_t	len_s1;
	size_t	len_s2;

	n = NULL;
	if (s1 || s2)
	{
		len_s1 = s1 ? ft_strlen(s1) : 0;
		len_s2 = s2 ? ft_strlen(s2) : 0;
		n = malloc(len_s1 + len_s2 + 1);
		if (n)
		{
			if (s1)
				ft_memcpy(n, s1, len_s1);
			i = len_s1;
			if (s2)
				ft_memcpy(&n[len_s1], s2, len_s2);
			i += len_s2;
			n[i] = '\0';
		}
	}
	return (n);
}
