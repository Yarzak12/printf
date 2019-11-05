/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 01:46:26 by slenore           #+#    #+#             */
/*   Updated: 2019/09/05 01:32:09 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(int n)
{
	int i;

	i = 1;
	while ((n = n / 10))
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		len;

	sign = 1;
	len = length(n);
	if (n < 0)
	{
		sign = -1;
		len++;
	}
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	if (sign == -1)
		str[0] = '-';
	while (len > -sign)
	{
		str[--len] = (n % 10) * sign + '0';
		n = n / 10;
	}
	return (str);
}
