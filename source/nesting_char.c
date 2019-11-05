/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nesting_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 06:33:15 by slenore           #+#    #+#             */
/*   Updated: 2019/10/27 06:38:04 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		flag_minch(t_token *t, char ostov, char *temp)
{
	ft_memset(temp, ' ', t->width);
	temp[0] = ostov;
	return (0);
}

int		flag_zrch(t_token *t, char ostov, char *temp, int w)
{
	ft_memset(temp, '0', t->width);
	temp[w - 1] = ostov;
	return (0);
}

int		nesting_char(t_token *token)
{
	char	ostov;
	char	*temp;
	int		w;

	ostov = ((char)(token->disc));
	w = token->width;
	if (w > 1)
	{
		temp = ft_strnew(token->width);
		if (token->f_min)
			flag_minch(token, ostov, temp);
		else if (token->f_zr)
			flag_zrch(token, ostov, temp, w);
		else
		{
			ft_memset(temp, ' ', token->width);
			temp[w - 1] = ostov;
		}
		ft_putstr(temp);
		ft_strdel(&temp);
		return (w);
	}
	ft_putchar(ostov);
	return (1);
}
