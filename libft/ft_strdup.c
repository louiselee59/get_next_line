/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:39:54 by lolee             #+#    #+#             */
/*   Updated: 2019/05/22 07:22:03 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*d;

	len = ft_strlen(s1);
	d = (char *)malloc(sizeof(char) * (len + 1));
	if (d)
	{
		d[len] = '\0';
		return (ft_strncpy(d, s1, len));
	}
	else
		return (d);
}
