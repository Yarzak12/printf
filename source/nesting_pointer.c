/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nesting_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:32:32 by slenore           #+#    #+#             */
/*   Updated: 2019/10/27 11:37:10 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	flag_minp(t_token *t, int len, char *st, char *tmp)
{
	int k;

	k = 2;
	ft_strcat(tmp, "0x");
	if (t->presicion - len > 0)
	{
		ft_memset(tmp + k, '0', t->presicion - len);
		k = t->presicion + 2;
	}
	else if (len >= t->presicion)
		k = len + 2;
	if (t->width > 0 || t->udisc)
		ft_strcat(tmp, st);
	if (t->width - ft_max(t->presicion, len) - 2 >= 0)
		ft_memset(tmp + k, ' ', t->width - ft_max(t->presicion, len) - 2);
	ft_strdel(&st);
	ft_putstr(tmp);
	len = ft_strlen(tmp);
	ft_strdel(&tmp);
	return (len);
}

int	flag_zrp(t_token *t, int len, char *st, char *tmp)
{
	int k;

	k = 2;
	if (t->presicion <= 0)
	{
		t->presicion = t->width - 2;
	}
	if (t->width - ft_max(t->presicion, len) - 2 >= 0)
	{
		ft_memset(tmp, '0', t->width - ft_max(t->presicion, len) - 2);
		k = t->width - ft_max(t->presicion, len);
	}
	ft_strcat(tmp, "0x");
	if (t->presicion - len >= 0)
		ft_memset(tmp + k, '0', t->presicion - len);
	if (t->width > 0 || t->udisc)
		ft_strcat(tmp, st);
	ft_strdel(&st);
	ft_putstr(tmp);
	len = ft_strlen(tmp);
	ft_strdel(&tmp);
	return (len);
}

int	flag_elsep(t_token *t, int len, char *st, char *tmp)
{
	int k;

	k = 2;
	if (t->width - ft_max(t->presicion, len) - 2 >= 0)
	{
		k = t->width - ft_max(t->presicion, len);
		ft_memset(tmp, ' ', t->width - ft_max(t->presicion, len) - 2);
	}
	ft_strcat(tmp, "0x");
	if (t->presicion - len >= 0)
	{
		ft_memset(tmp + k, '0', t->presicion - len);
	}
	ft_strcat(tmp, st);
	ft_strdel(&st);
	ft_putstr(tmp);
	len = ft_strlen(tmp);
	ft_strdel(&tmp);
	return (len);
}

int	nesting_pointer(t_token *t)
{
	char	*st;
	char	*tmp;
	int		len;

	st = ft_ultoa_base(t->udisc, 16, 1);
	len = ft_strlen(st);
	tmp = srmax(t, len);
	if (t->f_min)
	{
		return (flag_minp(t, len, st, tmp));
	}
	else if (t->f_zr)
	{
		return (flag_zrp(t, len, st, tmp));
	}
	else
	{
		return (flag_elsep(t, len, st, tmp));
	}
}
