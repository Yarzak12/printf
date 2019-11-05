/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gett_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 04:38:41 by slenore           #+#    #+#             */
/*   Updated: 2019/10/27 04:46:26 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	get_di(t_token *packet, va_list ap)
{
	char *mod;

	mod = packet->modificator;
	if (!mod || ft_strequ(mod, "l") || mod[0] == 'h')
		packet->disc = va_arg(ap, int);
	else if (ft_strequ(mod, "ll"))
		packet->disc = va_arg(ap, long long int);
	else if (ft_strequ(mod, "z"))
		packet->disc = va_arg(ap, size_t);
	else if (ft_strequ(mod, "L"))
		packet->disc = va_arg(ap, __int64_t);
}

void	get_oux(t_token *packet, va_list ap)
{
	char *mod;

	mod = packet->modificator;
	if (!mod || ft_strequ(mod, "l") || mod[0] == 'h')
		packet->udisc = va_arg(ap, int);
	else if (ft_strequ(mod, "ll"))
		packet->udisc = va_arg(ap, long long int);
	else if (ft_strequ(mod, "z"))
		packet->udisc = va_arg(ap, size_t);
	else if (ft_strequ(mod, "L"))
		packet->udisc = va_arg(ap, __int64_t);
}

void	get_else(t_token *packet, va_list ap)
{
	char *mod;

	mod = packet->modificator;
	if (ft_strchr("aAeEfFgG", packet->type))
	{
		if (!mod)
			packet->swim = va_arg(ap, double);
		else if (ft_strequ(mod, "L"))
			packet->swim = va_arg(ap, long double);
	}
	else if (packet->type == 'c' && !mod)
		packet->disc = va_arg(ap, int);
	else if (packet->type == 'c' && mod[0] == 'l')
		packet->disc = va_arg(ap, wint_t);
	else if (packet->type == 's' && !mod)
		packet->value = va_arg(ap, char*);
	else if (packet->type == 's' && mod[0] == 'l')
		packet->value = va_arg(ap, wchar_t*);
}

void	get_element(t_token *packet, va_list ap)
{
	if (packet->type == '_')
		return ;
	else if (ft_strchr("di", packet->type))
	{
		get_di(packet, ap);
	}
	else if (ft_strchr("ouxX", packet->type))
	{
		get_oux(packet, ap);
	}
	else if(packet->type == 'p')
	{
		packet->udisc = va_arg(ap, unsigned long int);
	}
	else
	{
		get_else(packet, ap);
	}
}

void	values(int size, t_token *packet, va_list ap)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (packet[i].order)
		{
			get_element(&packet[i], ap);
		}
		i++;
	}
}
