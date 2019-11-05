/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 02:03:22 by slenore           #+#    #+#             */
/*   Updated: 2019/09/06 19:00:11 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	octet1;
	unsigned char	octet2;

	if (fd >= 0)
	{
		if (c < 0)
		{
			octet1 = ((unsigned char)c >> 6) | 192;
			octet2 = ((unsigned char)c & 63) | 128;
			write(fd, &octet1, 1);
			write(fd, &octet2, 1);
		}
		else
			write(fd, &c, 1);
	}
}
