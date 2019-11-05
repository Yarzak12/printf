/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 01:07:50 by slenore           #+#    #+#             */
/*   Updated: 2019/10/23 19:14:11 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	res = ft_strnew(len);
	if (res == NULL || s == NULL)
		return (0);
	i = 0;
	while (i < len)
		res[i++] = s[start++];
	return (res);
}
