/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 05:15:36 by lolee             #+#    #+#             */
/*   Updated: 2019/05/26 21:18:29 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*n;
	int		i;

	n = NULL;
	if (s && f)
	{
		n = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (n)
		{
			i = 0;
			while (s[i] != '\0')
			{
				n[i] = f(i, s[i]);
				i = i + 1;
			}
			n[i] = '\0';
		}
	}
	return (n);
}
