/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:48:01 by slenore           #+#    #+#             */
/*   Updated: 2019/09/06 12:36:01 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 1 + ft_strlen(s);
	while (i-- > 0)
	{
		if (s[i] == (char)c)
			return ((char*)(s + i));
	}
	return (NULL);
}
