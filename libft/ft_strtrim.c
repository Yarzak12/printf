/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 01:24:05 by slenore           #+#    #+#             */
/*   Updated: 2019/09/06 14:38:21 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;
	char	*res;
	size_t	k;

	if (!s)
		return (NULL);
	if ((len = ft_strlen(s)))
		len--;
	i = 0;
	k = 0;
	while ((s[len] == ' ' || s[len] == '\t' || s[len] == '\n') && len > i)
		len--;
	if (len == 0 || *s == '\0')
		return (ft_strnew(0));
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && i < len)
		i++;
	if (!(res = ft_strnew(len - i + 1)))
		return (NULL);
	while (i <= len)
		res[k++] = s[i++];
	return (res);
}
