/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_shorter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:31:26 by lolee             #+#    #+#             */
/*   Updated: 2019/05/31 16:37:06 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Need to check escape code ex.\200
*/

static	int	ft_sum_up_digits(const char *str, int sign)
{
	int		i;
	int		k;
	int		digit_count;

	digit_count = 0;
	i = 0;
	k = 0;
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
	{
		k = k * 10 + (str[i] - '0');
		if (++digit_count > DIGIT_CUNT)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		i++;
	}
	return (k * sign);
}

static	int	ft_skip_blanks(const char *str, int i)
{
	while (str[i] <= 32 || str[i] == 126)
		i++;
	return (i);
}

static	int	ft_skip_0s_before_sign(const char *str, int i)
{
	while (str[i] == '0')
		i++;
	return (i);
}

static	int	ft_skip_non_digits(const char *str, int i)
{
	if (str[i] <= 48 && str[i] >= 57)
		return (0);
	while (str[i] == '0')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		j;
	int		sign;
	int		zero_before_sign;

	i = 0;
	sign = 1;
	zero_before_sign = 0;
	if (str[i] == '\e' || str[i] == '\200')
		return (0);
	i = ft_skip_blanks(str, i);
	j = i;
	i = ft_skip_0s_before_sign(str, i);
	if (i != j)
		zero_before_sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (zero_before_sign)
			return (0);
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	i = ft_skip_non_digits(str, i);
	return (ft_sum_up_digits(&str[i], sign));
}
