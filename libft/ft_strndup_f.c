/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:59:20 by slenore           #+#    #+#             */
/*   Updated: 2019/10/23 19:14:31 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup_f(char *s1, int n)
{
	char *dest;

	if (!(dest = ft_strndup(s1, n)))
		return (NULL);
	ft_strdel(&s1);
	return (dest);
}
