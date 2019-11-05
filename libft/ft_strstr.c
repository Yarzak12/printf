/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:56:37 by slenore           #+#    #+#             */
/*   Updated: 2019/09/06 12:47:28 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	size_t		ls;
	size_t		lf;
	char		*c;
	size_t		k;

	c = (char*)str;
	ls = ft_strlen(str);
	if (!(lf = ft_strlen(find)))
		return ((char*)str);
	k = 0;
	while (k < ls)
	{
		if (!ft_memcmp(c + k, find, lf))
			return (c + k);
		k++;
	}
	return (NULL);
}
