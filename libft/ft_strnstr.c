/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:31:04 by lolee             #+#    #+#             */
/*   Updated: 2019/07/03 15:24:50 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	segmentation fault on NULL pointers happens on de-referencing the NULL
**	pointer.
**	h = (char *)haystack  does not cause seg-fault.
*/

static char		*ft_search(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*t;
	char	*needle_tail;
	size_t	len_of_needle;

	len_of_needle = ft_strlen(needle);
	h = (char *)haystack;
	t = (char *)(haystack + len_of_needle - 1);
	needle_tail = (char *)(needle + len_of_needle - 1);
	while ((len >= (len_of_needle - 1)) && *h != '\0' && *t != '\0')
	{
		if (*h == *needle && *t == *needle_tail)
		{
			if (h == t || ft_strncmp(h + 1, needle + 1, len_of_needle - 2) == 0)
				return (h);
		}
		h++;
		t++;
		len--;
	}
	return (0);
}

char			*ft_strnstr(const char *haystack, \
							const char *needle, size_t len)
{
	size_t	len_of_needle;
	char	*h;

	if (*needle == '\0')
		return ((char *)haystack);
	len_of_needle = ft_strlen(needle);
	if (len == 0)
		return (0);
	if (len_of_needle == 1)
	{
		h = ft_strchr(haystack, *needle);
		if (((unsigned long)h - (unsigned long)haystack + 1) <= len)
			return (h);
		else
			return (0);
	}
	return (ft_search(haystack, needle, len));
}
