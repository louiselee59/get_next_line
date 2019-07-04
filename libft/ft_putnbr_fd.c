/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 06:27:51 by lolee             #+#    #+#             */
/*   Updated: 2019/05/24 15:25:34 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbl;
	int		a;
	int		b;

	nbl = (long)n;
	if (nbl >= MIN_INT4 && nbl <= MAX_INT4)
	{
		if (nbl < 0)
		{
			ft_putchar_fd('-', fd);
			nbl = nbl * -1;
		}
		a = nbl / 10;
		b = nbl % 10;
		if (a != 0)
			ft_putnbr_fd(a, fd);
		ft_putchar_fd(b + '0', fd);
	}
}
