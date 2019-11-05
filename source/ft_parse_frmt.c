/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_frmt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 04:47:13 by slenore           #+#    #+#             */
/*   Updated: 2019/10/27 04:53:06 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*tok_end(char *first)
{
	char	*types;
	char	*temp;
	char	*end;
	int		i;

	types = "diouxXfFeEgGaAcs%p";
	i = 0;
	end = NULL;
	while (types[i])
	{
		if ((temp = strchr(first + 1, types[i])))
		{
			if (temp - first < end - first || !end)
				end = temp;
		}
		i++;
	}
	if (end)
		return (end);
	else
		return (NULL);
}

void	perce_token(char **first, char *next, char **t)
{
	next = tok_end(*first);
	if (next)
	{
		*t = ft_strsub(*first, 0, next - *first + 1);
		*first = next + 1;
	}
}

char	**tokenizer(char *format)
{
	char	**tokens;
	int		i;
	char	*first;
	char	*next;

	tokens = (char **)malloc(ft_strlen(format) * sizeof(char*));
	first = format;
	i = 0;
	while (first)
	{
		if (*first == '%')
			perce_token(&first, next, &tokens[i]);
		else
		{
			next = ft_strchr(first, '%');
			if (next)
				tokens[i] = ft_strsub(first, 0, next - first);
			else
				tokens[i] = ft_strdup(first);
			first = next;
		}
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
