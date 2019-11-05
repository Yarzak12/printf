/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nesting_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 07:44:42 by slenore           #+#    #+#             */
/*   Updated: 2019/10/27 07:47:53 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		flag_minstr(t_token *t, char *st, char *tmp, int len)
{
	ft_strcat(tmp, st);
	ft_memset(tmp + len, ' ', t->width - len);
	return (0);
}

int		flag_zrstr(t_token *t, char *st, char *tmp, int len)
{
	ft_memset(tmp, '0', t->width - len);
	ft_strcat(tmp, st);
	return (0);
}

int		flag_elsestr(t_token *t, char *st, char *tmp, int len)
{
	ft_memset(tmp, ' ', t->width - len);
	ft_strcat(tmp, st);
	return (0);
}

int		nesting_str(t_token *t)
{
	char	*st;
	char	*tmp;
	int		len;

	tmp = (char*)(t->value);
	len = ft_strlen(tmp);
	if (t->presicion >= 0)
		st = ft_strsub(((char*)(t->value)), 0, ft_min(t->presicion, len));
	else
		st = ((char*)(t->value));
	len = ft_strlen(st);
	if (t->width < len)
		t->width = len;
	if (t->width >= t->presicion)
		tmp = ft_strnew(t->width);
	else
	{
		ft_putstr(st);
		return (len);
	}
	if (t->f_min)
		flag_minstr(t, st, tmp, len);
	else if (t->f_zr)
		flag_zrstr(t, st, tmp, len);
	else
		flag_elsestr(t, st, tmp, len);
	ft_putstr(tmp);
	return (t->width);
}
