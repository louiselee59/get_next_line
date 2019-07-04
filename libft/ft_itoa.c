/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:38:16 by lolee             #+#    #+#             */
/*   Updated: 2019/05/31 16:37:58 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_generate_ascii(char *p, int i, long num)
{
	long	a;
	long	b;
	char	*q;

	b = num % 10;
	a = num / 10;
	while (a != 0)
	{
		p[i] = b + '0';
		i = i + 1;
		b = a % 10;
		a = a / 10;
	}
	p[i] = b + '0';
	p[i + 1] = '\0';
	if (!(i + 1 == 2 && p[0] == '-') || !(i + 1 == 1))
	{
		if (p[0] == '-')
			q = ft_strrev(p + 1);
		else
			q = ft_strrev(p);
	}
	return (p);
}

static long	ft_set_negative_sign(char *p, int i, long num)
{
	if (num < 0)
	{
		p[i] = '-';
		num = num * -1;
	}
	return (num);
}

static int	ft_number_of_digits_sign(int nbr)
{
	int		i;
	long	a;

	i = 1;
	a = nbr / 10;
	while (a != 0)
	{
		i++;
		a /= 10;
	}
	if (nbr < 0)
		i++;
	return (i);
}

char		*ft_itoa(int nbr)
{
	long	num;
	char	*p;
	int		i;

	i = ft_number_of_digits_sign(nbr);
	p = (char *)malloc(sizeof(char) * i + 1);
	if (p)
	{
		num = (long)nbr;
		num = ft_set_negative_sign(p, 0, num);
		if (nbr < 0)
			p = ft_generate_ascii(p, 1, num);
		else
			p = ft_generate_ascii(p, 0, num);
	}
	return (p);
}
