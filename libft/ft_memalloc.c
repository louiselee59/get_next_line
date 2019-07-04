/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:31:59 by lolee             #+#    #+#             */
/*   Updated: 2019/05/26 20:57:53 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*p;
	size_t	i;

	if (size == 0 || size > MAX_INT4)
		return (NULL);
	p = (char *)malloc(sizeof(char) * size);
	if (p != NULL)
	{
		i = 0;
		while (i < size)
			p[i++] = '\0';
		return ((void *)p);
	}
	else
		return (NULL);
}
