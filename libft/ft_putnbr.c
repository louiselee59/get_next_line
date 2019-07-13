/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 10:17:03 by lolee             #+#    #+#             */
/*   Updated: 2019/05/24 14:48:33 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	long	nbl;
	int		a;
	int		b;

	nbl = (long)nb;
	if (nbl >= MIN_INT4 && nbl <= MAX_INT4)
	{
		if (nbl < 0)
		{
			ft_putchar('-');
			nbl = nbl * -1;
		}
		a = nbl / 10;
		b = nbl % 10;
		if (a != 0)
			ft_putnbr(a);
		ft_putchar(b + '0');
	}
}
