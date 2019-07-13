/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 10:55:17 by lolee             #+#    #+#             */
/*   Updated: 2019/05/22 13:55:57 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	int		idx;
	size_t	i;

	if (n <= 0)
		return (s1);
	idx = ft_strlen(s1);
	i = 0;
	while (&s1[idx] && s2[i] != '\0' && i < n)
	{
		s1[idx] = s2[i];
		idx = idx + 1;
		i = i + 1;
	}
	if (&s1[idx])
		s1[idx] = '\0';
	return (s1);
}
