/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 11:19:00 by lolee             #+#    #+#             */
/*   Updated: 2019/05/23 11:53:12 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	letter;

	letter = (char)c;
	i = 0;
	if (letter == '\0')
	{
		while (s[i] != '\0')
			i++;
		return ((char *)&s[i]);
	}
	else
	{
		while (s[i] != '\0' && s[i] != letter)
			i++;
		if (s[i] == '\0')
			return (NULL);
		else
			return ((char *)&s[i]);
	}
}
