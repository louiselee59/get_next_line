/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 20:21:26 by lolee             #+#    #+#             */
/*   Updated: 2019/05/31 16:43:26 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	(size >= 0) will always be true, because size_t is positive int.
**	int len = size supports test condition (len >=0)
*/

char	*ft_strnew(size_t size)
{
	char	*p;
	int		len;

	len = size;
	p = (char *)malloc(sizeof(char) * (size + 1));
	if (p)
	{
		while (len >= 0)
		{
			p[len] = '\0';
			len--;
		}
	}
	return (p);
}
