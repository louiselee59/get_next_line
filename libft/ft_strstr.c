/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:30:29 by lolee             #+#    #+#             */
/*   Updated: 2019/05/17 16:12:31 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *str, char const *to_find)
{
	int		i;
	int		j;

	if (to_find[0] == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return ((char *)&str[i]);
			else
				j = j + 1;
		}
		i = i + 1;
	}
	return (NULL);
}
