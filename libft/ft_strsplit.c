/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 06:07:21 by lolee             #+#    #+#             */
/*   Updated: 2019/07/03 15:23:32 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  try ft_striter
*/

static	int			ft_skip_delimiters(char const *s, int i, char c)
{
	while (s[i] == c)
		i++;
	return (i);
}

static t_result		ft_capture_a_word(char const *s, int i, char c)
{
	int			k;
	int			h;
	int			i1;
	t_result	ans;
	char		*p;

	k = 0;
	h = i;
	while (s[i] != '\0' && s[i] != c)
	{
		k++;
		i++;
	}
	p = (char *)malloc(sizeof(char) * k + 1);
	i1 = 0;
	while (k > 0)
	{
		p[i1++] = s[h++];
		k--;
	}
	p[i1] = '\0';
	ans.p = (void *)p;
	ans.idx = i;
	return (ans);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**n;
	int			j;
	t_result	ans;

	ans.p = 0;
	ans.idx = 0;
	j = 0;
	if (!s)
		return (NULL);
	n = (char **)malloc(sizeof(char *) * ft_strlen(s) + 1);
	if (n)
	{
		while (s[ans.idx] != '\0')
		{
			ans.idx = ft_skip_delimiters(s, ans.idx, c);
			if (s[ans.idx] != '\0')
			{
				ans = ft_capture_a_word(s, ans.idx, c);
				n[j++] = (char *)ans.p;
			}
		}
		n[j] = (void *)0;
	}
	return (n);
}
