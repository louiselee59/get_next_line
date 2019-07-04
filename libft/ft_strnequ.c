/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 05:30:47 by lolee             #+#    #+#             */
/*   Updated: 2019/05/31 16:42:34 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	return 1 if equal, otherwise, return 0
**	(NULL, NULL) ?,	("", "") ?, (NULL, "") ?, ("", NULL) ?
*/

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		i;

	if (!s1 || !s2)
		return (0);
	if (*s2 == '\0' && n == 0)
		return (1);
	if (*s1 == '\0' && *s2 != '\0')
		return (0);
	i = ft_strncmp(s1, s2, n);
	if (i == 0)
		return (1);
	else
		return (0);
}
