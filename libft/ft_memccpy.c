/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:39:11 by slenore           #+#    #+#             */
/*   Updated: 2019/09/05 20:05:03 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*src_ptr;
	unsigned char	*dst_ptr;
	size_t			i;

	src_ptr = (unsigned char*)src;
	dst_ptr = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		if (src_ptr[i] == (unsigned char)c)
			return ((void*)(dst_ptr + i + 1));
		i++;
	}
	return (NULL);
}
