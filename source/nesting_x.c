/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nesting_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 08:15:04 by slenore           #+#    #+#             */
/*   Updated: 2019/10/27 08:25:12 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*mod(t_token *t)
{
	char *mod;

	mod = NULL;
	if (t->type == 'x')
		mod = ft_strdup("0x");
	else if (t->type == 'X')
		mod = ft_strdup("0X");
	else if (t->type == 'o')
		mod = ft_strdup("0o");
	return (mod);
}

int		flag_minx(t_token *t, int len, char *st, char *tmp)
{
	if (t->presicion >= len)
		ft_memset(tmp, ' ', t->presicion - len);
	if (t->f_oct && t->udisc)
	{
		ft_strcat(tmp, mod(t));
	}
	if (t->udisc >0 || t->presicion != 0)
		ft_strcat(tmp, st);
	ft_strdel(&st);
	if (t->width - ft_max(len, t->presicion) - t->f_oct >= 0 && t->udisc != 0)
		ft_memset(tmp + ft_max(len, t->presicion) + t->f_oct,' ', t->width - ft_max(len, t->presicion) - t->f_oct);
	else if (t->width - ft_max(t->presicion, len) >= 0 && t->udisc == 0 )
		ft_memset(tmp + ft_max(len, t->presicion) ,' ', t->width - ft_max(len, t->presicion));
	ft_putstr(tmp);
	len = ft_strlen(tmp);
	ft_strdel(&tmp);
	return (len);
}

int		flag_zrx(t_token *t, int len, char *st, char *tmp)
{
	if (t->width == 0 && t->udisc != 0)
		t->width = t->presicion + t->f_oct;
	else if (t->width < t->presicion)
		t->width = t->presicion;
	if (t->width - ft_max(t->presicion, len) - t->f_oct >= 0 && t->udisc != 0)
		ft_memset(tmp, ' ', t->width - ft_max(t->presicion, len) - t->f_oct);
	else if (t->width - ft_max(t->presicion, len) >= 0 && t->udisc == 0 )
		ft_memset(tmp, ' ', t->width - ft_max(t->presicion, len));
	else
		t->width += 2;//p>w
	if (t->f_oct && t->udisc)
		ft_strcat(tmp, mod(t));
	if (t->presicion > len)
		ft_memset(tmp + t->width - t->presicion, '0', t->presicion - len);
	if (st[0] != '0' || t->presicion != 0)
	{
		ft_strcat(tmp, st);
	}
	ft_strdel(&st);
	ft_putstr(tmp);
	len = ft_strlen(tmp);
	ft_strdel(&tmp);
	return (len);
}

int		flag_elsex(t_token *t, int len, char *st, char *tmp)
{
	if (t->width == 0 && t->udisc != 0)
		t->width = t->presicion + t->f_oct;
	else if (t->width < t->presicion)
		t->width = t->presicion;
	if (t->width - ft_max(t->presicion, len) - t->f_oct >= 0 && t->udisc != 0)
		ft_memset(tmp, ' ', t->width - ft_max(t->presicion, len) - t->f_oct);
	else if (t->width - ft_max(t->presicion, len) >= 0 && t->udisc == 0 )
		ft_memset(tmp, ' ', t->width - ft_max(t->presicion, len));
	else
		t->width += 2;//p>w
	if (t->f_oct && t->udisc)
		ft_strcat(tmp, mod(t));
	if (t->presicion > len)
		ft_memset(tmp + t->width - t->presicion, '0', t->presicion - len);
	if (st[0] != '0' || t->presicion != 0)
	{
		ft_strcat(tmp, st);
	}
	ft_strdel(&st);
	ft_putstr(tmp);
	len = ft_strlen(tmp);
	ft_strdel(&tmp);
	return (len);
}

int		nesting_x(t_token *t)
{
	char	*st;
	char	*tmp;
	int		len;

	if (t->type == 'x')
		st = ft_ultoa_base(t->udisc, 16, 1);
	else if (t->type == 'X')
		st = ft_ultoa_base(t->udisc, 16, 0);
	else if (t->type == 'o')
		st = ft_ultoa_base(t->udisc, 8, 1);
	len = ft_strlen(st);
	tmp = srmax(t, len);
	if (t->f_min)
	{
		return (flag_minx(t, len, st, tmp));
	}
	else if (t->f_zr)
	{
		return (flag_zrx(t, len, st, tmp));
	}
	else
	{
		return (flag_elsex(t, len, st, tmp));
	}
}
