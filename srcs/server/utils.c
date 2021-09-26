/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 21:52:39 by vico              #+#    #+#             */
/*   Updated: 2021/09/25 21:53:07 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	bin_to_dec(char *nb)
{
	int	ret;
	int	div;
	int	i;

	ret = 0;
	div = 128;
	i = -1;
	while (++i < 8)
	{
		ret = ret + ((nb[i] - '0') * div);
		div /= 2;
	}
	return (ret);
}

void	full_zero(char *s)
{
	int	i;

	i = -1;
	while (++i < 8)
		s[i] = '0';
}

int	only_zero(char nb[8])
{
	int	i;
	int	ok;

	i = -1;
	ok = 1;
	while (++i < 8)
	{
		if (nb[i] == '1')
			ok = 0;
	}
	return (ok);
}
