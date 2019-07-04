/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 21:10:10 by lolee             #+#    #+#             */
/*   Updated: 2019/05/23 18:35:15 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*p;
	int		i;

	p = NULL;
	if (s && f)
	{
		p = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		i = 0;
		if (p)
		{
			while (s[i] != '\0')
			{
				p[i] = f(s[i]);
				i = i + 1;
			}
			p[i] = '\0';
		}
	}
	return (p);
}
