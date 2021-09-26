/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:21:08 by vico              #+#    #+#             */
/*   Updated: 2021/09/25 16:22:07 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	full_zero(char *s)
{
	int	i;

	i = -1;
	while (++i < 8)
		s[i] = '0';
	s[i] = '\0';
}

char	*dec_to_bin(int nb)
{
	char	*ret;
	int		i;

	i = 8;
	ret = malloc(sizeof(char) * 9);
	if (!(ret))
		return (NULL);
	full_zero(ret);
	while (nb)
	{
		ret[--i] = (nb - ((nb / 2) * 2)) + '0';
		nb = nb / 2;
	}
	return (ret);
}
