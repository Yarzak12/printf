/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 05:45:04 by slenore           #+#    #+#             */
/*   Updated: 2019/09/06 01:00:28 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*dest;

	list = (t_list*)malloc(sizeof(t_list));
	dest = ft_memalloc(content_size);
	if (list == NULL)
		return (NULL);
	list->next = NULL;
	if (content != NULL)
		list->content = ft_memcpy(dest, content, content_size);
	else
		list->content = NULL;
	if (content == NULL)
		list->content_size = 0;
	else
		list->content_size = content_size;
	return (list);
}
