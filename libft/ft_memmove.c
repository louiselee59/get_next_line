/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 21:23:38 by lolee             #+#    #+#             */
/*   Updated: 2019/05/22 06:43:19 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memmove_backwards(void *dst, const void *src, size_t length)
{
	size_t		t;
	char		*d;
	char const	*s;

	d = dst;
	s = src;
	s += length;
	d += length;
	t = length / 1;
	while (t > 0)
	{
		s -= 1;
		d -= 1;
		*d = *s;
		t--;
	}
}

static void	ft_memmove_forwards(void *dst, const void *src, size_t length)
{
	size_t		t;
	char		*d;
	char const	*s;

	d = dst;
	s = src;
	t = length / 1;
	while (t > 0)
	{
		*d = *s;
		s += 1;
		d += 1;
		t--;
	}
}

void		*ft_memmove(void *dst, const void *src, size_t length)
{
	if (!dst && !src)
		return (dst);
	if (src < dst)
		ft_memmove_backwards(dst, src, length);
	else
		ft_memmove_forwards(dst, src, length);
	return (dst);
}
