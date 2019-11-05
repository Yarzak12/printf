/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 00:14:31 by slenore           #+#    #+#             */
/*   Updated: 2019/09/06 12:55:24 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	wordlen(size_t k, char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[k + i] != c && str[k + i])
		i++;
	return (i);
}

static char		**ft_realloc(char **arr, size_t w)
{
	char	**tarr;
	size_t	i;

	i = 0;
	tarr = (char**)malloc(8 * (w + 1));
	while (i < w)
	{
		tarr[i] = arr[i];
		i++;
	}
	tarr[i] = NULL;
	return (tarr);
}

char			**ft_strsplit(char const *str, char c)
{
	size_t	i;
	size_t	w;
	size_t	size;
	char	**arr;

	if (!str)
		return (NULL);
	i = 0;
	w = 0;
	if (!(arr = (char**)malloc(8 * (ft_strlen(str) / 2 + 1))))
		return (NULL);
	while (str[i])
	{
		if (str[i] != c && str[i])
		{
			size = wordlen(i, str, c);
			arr[w++] = ft_strsub(str, i, size);
			i = i + size;
		}
		else
			i++;
	}
	return ((arr = ft_realloc(arr, w)));
}
