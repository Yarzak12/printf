/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:19:45 by slenore           #+#    #+#             */
/*   Updated: 2019/09/06 13:51:29 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **alst, t_list *new)
{
	t_list *begin;

	begin = *alst;
	if (alst == NULL)
		return ;
	if (begin == NULL)
	{
		begin = new;
	}
	else
	{
		while (begin->next)
		{
			begin = begin->next;
		}
		begin->next = new;
	}
}
