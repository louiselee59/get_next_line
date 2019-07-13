/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:22:05 by lolee             #+#    #+#             */
/*   Updated: 2019/07/03 15:22:04 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_special_case_check(const char *s1, const char *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	int				i;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 99;
	if (n == 0 || (*a == '\0' && *b == '\0'))
		i = 0;
	else if (*s1 != '\0' && *s2 == '\0')
		i = 1;
	else if (*s1 == '\0' && *s2 != '\0')
		i = -1;
	return (i);
}

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	int				ans;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if ((ans = ft_special_case_check(s1, s2, n)) != 99)
		return (ans);
	while (n > 0 && *a != '\0' && *b != '\0')
	{
		ans = *a - *b;
		if (ans != 0)
			return (ans);
		n = n - 1;
		a = a + 1;
		b = b + 1;
	}
	if (n == 0)
		return (ans);
	else
	{
		ans = *a - *b;
		return (ans);
	}
}
