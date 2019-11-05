/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nesting_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 01:55:16 by slenore           #+#    #+#             */
/*   Updated: 2019/10/27 07:07:22 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		flag_min(t_token *t, int len, char *st, char *tmp)
{
	int		k;

	k = k_factor(t);
	if (t->sign < 0)
		ft_strcat(tmp, "-");
	else if (t->f_pls)
		ft_strcat(tmp, "+");
	else if (t->f_spc)
		tmp[0] = ' ';
	if (t->presicion >= len)
		ft_memset(tmp + k, '0', t->presicion - len);
	if (st[0] != '0' || t->presicion != 0)
	{
		ft_strcat(tmp, st);
	}
	ft_strdel(&st);
	if (t->width - ft_max(len, t->presicion) - k > 0)
		ft_memset(tmp + ft_max(len, t->presicion) + k
				, ' ', t->width - ft_max(len, t->presicion) - k);
	ft_putstr(tmp);
	len = ft_strlen(tmp);
	ft_strdel(&tmp);
	return (len);
}

int		flag_zr(t_token *t, int len, char *st, char *tmp)
{
	int		k;

	k = k_factor(t);
	if (st[0] == '0' && t->presicion <= 0)
		t->width++;
	if (t->presicion == -1)
		t->presicion = t->width - k;
	if (t->width == 0)
		t->width = t->presicion + k;
	if (t->width - ft_max(t->presicion, len) - k >= 0)
		ft_memset(tmp + t->f_spc, '0',
				t->width - ft_max(t->presicion, len) - k);
	else
		t->width++;//p>w
	if (t->sign < 0)
		ft_strcat(tmp, "-");
	else if (t->f_pls)
		ft_strcat(tmp, "+");
	else if (t->f_spc)
		tmp[0] = ' ';
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

int		flag_pls(t_token *t, int len, char *st, char *tmp)
{
	int		k;

	k = k_factor(t);
	if (t->width == 0)
		t->width = t->presicion + k;
	if (t->width - ft_max(t->presicion, len) - k >= 0)
		ft_memset(tmp + t->f_spc, ' ', t->width - ft_max(t->presicion, len) - k);
	else
		t->width++;//p>w
	if (t->sign < 0)
		ft_strcat(tmp, "-");
	else if (t->f_pls)
		ft_strcat(tmp, "+");
	else if (t->f_spc)
		tmp[0] = ' ';
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

int		flag_else(t_token *t, int len, char *st, char *tmp)
{
	int k;

	k = k_factor(t);
	if (t->width == 0)
		t->width = t->presicion + k;
	if (t->width - ft_max(t->presicion, len) - k >= 0)
		ft_memset(tmp + t->f_spc, ' ', t->width - ft_max(t->presicion, len) - k);
	else
		t->width++;//p>w
    if (t->sign < 0)
		ft_strcat(tmp, "-");
	else if (t->f_spc)
		tmp[0] = ' ';
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

int		nesting_di(t_token *t)
{
	char	*st;
	char	*tmp;
	int		len;

	st = ft_itoa(ft_abs(t->disc));
	t->sign = ft_sign(t->disc);
	len = ft_strlen(st);
	tmp = srmax(t, len);
	if (t->f_min)
	{
		return (flag_min(t, len, st, tmp));
	}
	else if (t->f_zr)
	{
		return (flag_zr(t, len, st, tmp));
	}
	else if (t->f_pls)
	{
		return (flag_pls(t, len, st, tmp));
	}
	else
	{
		return (flag_else(t, len, st, tmp));
	}
}
