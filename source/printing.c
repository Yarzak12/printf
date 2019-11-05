/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 08:05:53 by slenore           #+#    #+#             */
/*   Updated: 2019/10/27 08:13:19 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		cs_print(t_token *packet)
{
	if (packet->type == '_')
	{
		ft_putstr(packet->value);

		return ft_strlen(packet->value);
	}
	else if (packet->type == 's' )
	{
		return	nesting_str(packet);
	}
	else if (packet->type == 'c')
	{
		return	nesting_char(packet);
	}
	else if (packet->type == 'p')
	{
		return	nesting_pointer(packet);
	}
	else
		return 0;
}

int			printing(t_token *packet, int size)
{
	int i;
	int sum;

	sum = 0;
	i = -1;
	while (++i < size)
	{
		if (ft_strchr("di", packet[i].type))
		{
			sum += nesting_di(&packet[i]);
		}
		else if (packet[i].type == 'u')
		{
			sum += nesting_u(&packet[i]);
		}
		else if (ft_strchr("Xxo", packet[i].type))
		{
			sum += nesting_x(&packet[i]);
		}
		else if (ft_strchr("cs_p%", packet[i].type))
		{
			sum += cs_print(&packet[i]);
		}


	}
	return sum;
}
