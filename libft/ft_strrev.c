/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:13:08 by lolee             #+#    #+#             */
/*   Updated: 2019/05/03 06:07:30 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		tail;
	int		head;
	char	tmp;

	tail = ft_strlen(str) - 1;
	head = 0;
	while (head < tail)
	{
		tmp = str[head];
		str[head] = str[tail];
		str[tail] = tmp;
		head = head + 1;
		tail = tail - 1;
	}
	return (str);
}
