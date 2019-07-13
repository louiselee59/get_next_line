/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 22:13:41 by lolee             #+#    #+#             */
/*   Updated: 2019/05/01 19:00:58 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if ((*(unsigned char *)s1) == (*(unsigned char *)s2))
		{
			n = n - 1;
			s1 = s1 + 1;
			s2 = s2 + 1;
		}
		else
			return ((*(unsigned char *)s1) - (*(unsigned char *)s2));
	}
	return (0);
}
