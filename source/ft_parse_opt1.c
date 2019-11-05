/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_opt1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 05:08:40 by slenore           #+#    #+#             */
/*   Updated: 2019/10/27 05:20:56 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	typification(char **pars, t_token *packet)
{
	int i;

	i = 0;
	while (pars[i])
	{
		if (pars[i][0] != '%')
		{
			packet[i].type = '_';
			packet[i].value = pars[i];
			packet[i].order = 0;
		}
		else
			packet[i].type = pars[i][ft_strlen(pars[i]) - 1];
		i++;
	}
}

void	precision(char **pars, t_token *packet)
{
	char	*end;
	char	*begin;
	char	*number;
	int		i;

	i = -1;
	while (pars[++i])
	{
		if (pars[i][0] == '%')
		{
			if ((end = ft_strchr(pars[i], '.')))
			{
				begin = end;
				while (ft_isdigit((++end)[0]))
					;
				number = ft_strsub(pars[i],
						begin - pars[i] + 1, end - begin - 1);
				packet[i].presicion = ft_atoi(number);
			}
			else if (packet->type == 's')
				packet[i].presicion = -1;
			else
				packet[i].presicion = -1;
		}
	}
}

void	width(char **pars, t_token *packet)
{
	int		begin;
	int		end;
	char	*number;
	int		i;
	int		k;

	i = -1;
	while (pars[++i])
	{
		if (pars[i][0] == '%' && (k = ft_strlen(pars[i])))
		{
			while (!ft_isdigit(pars[i][k]) && k > 0)
				--k;
			if ((number = ft_strchr(pars[i], '.')))
				k = number - pars[i] - 1;
			end = k;
			while (ft_isdigit(pars[i][k]))
				k--;
			begin = k + 1;
			number = ft_strsub(pars[i], begin, end - begin + 1);
			if (number[0] == '\0')
				number = ft_strdup("0");
			packet[i].width = ft_atoi(number);
		}
	}
}
