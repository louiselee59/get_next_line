/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 05:59:11 by lolee             #+#    #+#             */
/*   Updated: 2019/05/31 16:48:32 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  use return (ft_strnew(1)) instead of return ("").  Because "" is not a
**  pointer that can be free outside of the scope of ft_strtrim.
*/

static int	ft_trim_front(char const *s)
{
	int i;

	i = 0;
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	return (i);
}

static int	ft_trim_back(char const *s, int i)
{
	while (s[i] != '\0')
		i++;
	i--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*n;
	int		i;
	int		j;
	int		idx;

	n = NULL;
	if (s)
	{
		i = ft_trim_front(s);
		if (s[i] == '\0')
			return (ft_strnew(1));
		idx = i;
		i = ft_trim_back(s, i);
		j = i - idx + 1;
		if (j > 0)
			n = (char *)malloc(sizeof(char) * j + 1);
		if (n)
		{
			ft_memcpy(n, &s[idx], j);
			n[j] = '\0';
		}
	}
	return (n);
}
