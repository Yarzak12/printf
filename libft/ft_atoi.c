/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:49:53 by slenore           #+#    #+#             */
/*   Updated: 2019/09/06 12:14:09 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define FT_LONG_MAX 9223372036854775807

static int	ft_overmax(int sign)
{
	if (sign == -1)
		return ((int)(-FT_LONG_MAX - 1));
	if (sign)
		return ((int)(FT_LONG_MAX));
	return (0);
}

int			ft_atoi(const char *str)
{
	int				sign;
	long long int	res;

	res = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-') ? -1 : 1;
	while (ft_isdigit(*str))
	{
		res = res * 10 + (int)(*str++ - '0');
		if (res >= (FT_LONG_MAX) / 10 && ft_isdigit(*str))
			return (ft_overmax(sign));
	}
	return (sign * res);
}
