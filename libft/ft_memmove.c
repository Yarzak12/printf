/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:48:03 by slenore           #+#    #+#             */
/*   Updated: 2019/09/04 16:46:08 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	size_t			i;

	i = 0;
	dst_ptr = (unsigned char*)dst;
	src_ptr = (unsigned char*)src;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len-- != 0)
			dst_ptr[len] = src_ptr[len];
	}
	else
	{
		while (i < len)
		{
			dst_ptr[i] = src_ptr[i];
			i++;
		}
	}
	return (dst);
}
