/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 01:46:26 by slenore           #+#    #+#             */
/*   Updated: 2019/10/23 19:04:48 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(unsigned long int n)
{
	int i;

	i = 1;
	while ((n = n / 10))
		i++;
	return (i);
}

char		*ft_ultoa(unsigned long int n)
{
	char	*str;
	int		len;

	len = length(n);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	while (len > -1)
	{
		str[--len] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
