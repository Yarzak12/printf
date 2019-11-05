/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:56:37 by slenore           #+#    #+#             */
/*   Updated: 2019/09/06 14:41:00 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	ls;
	size_t	lf;
	char	*c;
	size_t	k;

	c = (char*)str;
	ls = ft_strlen(str);
	if (!(lf = ft_strlen(find)))
		return ((char*)str);
	ls = (len > ls) ? ls : len;
	k = 0;
	while (k < ls)
	{
		if (!ft_memcmp(c + k, find, lf) && k + lf <= ls)
			return (c + k);
		k++;
	}
	return (NULL);
}
