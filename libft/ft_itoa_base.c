/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:43:36 by slenore           #+#    #+#             */
/*   Updated: 2019/10/23 19:24:20 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_length(long long int nb, int base)
{
	int		i;

	i = 1;
	if (nb < 0)
		i++;
	while ((nb = nb / base))
	{
		i++;
	}
	return (i);
}

char		*ft_itoa_base(long int nb, int base)
{
	char	*str;
	int		len;
	int		sign;

	sign = 0;
	len = nb_length(nb, base);
	str = (char *)malloc((len + 1) * (sizeof(char)));
	str[len] = '\0';
	if (nb < 0)
	{
		sign = 1;
		nb = -nb;
		str[0] = '-';
	}
	while (len - sign)
	{
		str[--len] =
		((nb % base) < 10) ? nb % base + '0' : nb % base + 'A' - 10;
		nb = nb / base;
	}
	return (str);
}
