/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:59:20 by slenore           #+#    #+#             */
/*   Updated: 2019/10/23 19:05:25 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	char	*dest;
	int	len;

	len = ft_strlen(s1);
	if (len > n)
		len = n;
	if (!(dest = ft_strnew(len)))
		return (NULL);
	ft_strncpy(dest, s1, len);
	return (dest);
}
