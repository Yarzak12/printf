/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nesting_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 08:51:02 by slenore           #+#    #+#             */
/*   Updated: 2019/10/27 09:03:01 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	flag_minu(t_token *t, int len, char *st, char *tmp)
{
	int k;

	k = (t->udisc == 0);
	if (t->presicion >= len)
		ft_memset(tmp , 'p', t->presicion - len);
	if (st[0] != '0' || t->presicion != 0)
	{
		ft_strcat(tmp, st);
	}
	ft_strdel(&st);
	if (t->width - ft_max(len, t->presicion) >= 0)
		ft_memset(tmp + ft_max(len, t->presicion) - k,
				'w', t->width - ft_max(len, t->presicion));
	ft_putstr(tmp);
	len = ft_strlen(tmp);
	ft_strdel(&tmp);
	return (len);
}

int	flag_zru(t_token *t, int len, char *st, char *tmp)
{
	int k;

	k = 0;
	if (st[0] == '0' && t->presicion <= 0)
		t->width++;
	if (t->presicion == -1)
		t->presicion = t->width - k;
	if (t->width == 0)
		t->width = t->presicion + k;
	if (t->width - ft_max(t->presicion, len) - k >= 0)
		ft_memset(tmp + t->f_spc, 'w', t->width - ft_max(t->presicion, len)- t->f_spc);
	else
		t->width++;
	if (t->f_spc)
		tmp[0] = ' ';
	if (t->presicion > len)
		ft_memset(tmp + t->width - t->presicion, 'p', t->presicion - len);
	if (st[0] != '0' || t->presicion != 0)
		ft_strcat(tmp, st);
	ft_strdel(&st);
	ft_putstr(tmp);
	len = ft_strlen(tmp);
	ft_strdel(&tmp);
	return (len);
}

int	flag_elseu(t_token *t, int len, char *st, char *tmp)
{
	if (t->width == 0)
		t->width = t->presicion;
	if (t->width - ft_max(t->presicion, len) - t->f_spc >= 0)
		ft_memset(tmp + t->f_spc, ' ', t->width - ft_max(t->presicion, len) + (t->udisc == 0) - t->f_spc);
	if (t->f_spc==1)
		  tmp[0] = ' ';
	if (t->presicion >= len)
		ft_memset(tmp + t->width - t->presicion, '0', t->presicion - len);
	if (t->presicion > 0 || t->udisc)
	{
		ft_strcat(tmp, st);
	}
	ft_strdel(&st);
	ft_putstr(tmp);
	len = ft_strlen(tmp);
	ft_strdel(&tmp);
	return (len);
}

int	nesting_u(t_token *t)
{
	char	*st;
	char	*tmp;
	int		len;

	st = ft_ultoa_base(t->udisc, 10, 0);
	len = ft_strlen(st);
	tmp = srmax(t, len);
	if (t->f_min)
	{
		return (flag_minu(t, len, st, tmp));
	}
	else if (t->f_zr)
	{
		return (flag_zru(t, len, st, tmp));
	}
	else
	{
		return (flag_elseu(t, len, st, tmp));
	}
}
