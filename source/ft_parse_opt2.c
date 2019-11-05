/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_opt2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 05:29:38 by slenore           #+#    #+#             */
/*   Updated: 2019/10/27 05:38:38 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		init_flags(char **pars, t_token *packet)
{
	int		i;

	i = 0;
	while (pars[i])
	{
		if (pars[i][0] == '%')
		{
			packet[i].f_oct = 0;
			packet[i].f_min = 0;
			packet[i].f_pls = 0;
			packet[i].f_spc = 0;
			packet[i].f_zr = 0;
			if ((ft_strchr(pars[i], '#')))
				packet[i].f_oct = 2;
			if ((ft_strchr(pars[i], '-')))
				packet[i].f_min = 1;
			if ((ft_strchr(pars[i], '+')))
				packet[i].f_pls = 1;
			if ((ft_strchr(pars[i], ' ')))
			{
				packet[i].f_spc = 1;
			}
		}
		i++;
	}
}

void			flags(char **pars, t_token *packet)
{
	char	*temp;
	int		i;

	i = 0;
	init_flags(pars, packet);
	while (pars[i])
	{
		if (pars[i][0] == '%')
		{
			if ((temp = ft_strchr(pars[i], '$')))
				;
			else
				temp = pars[i];
			while (!ft_isdigit(*temp) && *temp != '\0' && *temp != '.')
				temp++;
			if (*temp == '0')
			{
				packet[i].f_zr = 1;
			}
		}
		i++;
	}
}

void			modificators(char **pars, t_token *packet)
{
	int		i;

	i = 0;
	while (pars[i])
	{
		if (pars[i][0] == '%')
		{
			if (ft_strstr(pars[i], "hh"))
				packet[i].modificator = ft_strdup("hh");
			else if (ft_strstr(pars[i], "h"))
				packet[i].modificator = ft_strdup("h");
			else if (ft_strstr(pars[i], "ll"))
				packet[i].modificator = ft_strdup("ll");
			else if (ft_strstr(pars[i], "l"))
				packet[i].modificator = ft_strdup("l");
			else if (ft_strstr(pars[i], "L"))
				packet[i].modificator = ft_strdup("L");
			else if (ft_strstr(pars[i], "z"))
				packet[i].modificator = ft_strdup("z");
			else
				packet[i].modificator = NULL;
		}
		i++;
	}
}

void			order(char **pars, t_token *packet)
{
	int		i;
	int		k;

	k = 0;
	i = 0;
	while (pars[i])
	{
		if (pars[i][0] == '%')
		{
			packet[i].order = ++k;
		}
		i++;
	}
}
