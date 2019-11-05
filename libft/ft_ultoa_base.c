/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:57:05 by slenore           #+#    #+#             */
/*   Updated: 2019/10/23 19:28:15 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_length(unsigned long int nb, int base)
{
	int i;

	i = 1;
	while ((nb = nb / base))
	{
		i++;
	}
	return (i);
}

char		*ft_ultoa_base(unsigned long int nb, int b, int f)
{
	char	*str;
	int		len;

	len = nb_length(nb, b);
	str = (char *)malloc((len + 1) * (sizeof(char)));
	str[len] = '\0';
	while (len)
	{
		str[--len] =
		((nb % b) < 10) ? nb % b + '0' : nb % b + 'A' - f * ('A' - 'a') - 10;
		nb = nb / b;
	}
	return (str);
}
