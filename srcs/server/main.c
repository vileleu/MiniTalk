/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 19:32:00 by vico              #+#    #+#             */
/*   Updated: 2021/11/02 18:50:37 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	norme_detect_signal(char *nb, int *identity, int *pid)
{
	if (only_zero(nb))
	{
		ft_putchar_fd('\n', 1);
		*identity = 0;
		kill(*pid, SIGUSR1);
		*pid = 0;
	}
	else
	{
		ft_putchar_fd(bin_to_dec(nb), 1);
		kill(*pid, SIGUSR1);
	}
}

void	detect_signal(int signum)
{
	static int	identity = 0;
	static int	pid = 0;
	static int	i = 0;
	static char	nb[8] = "00000000";

	if (signum == SIGUSR1)
		nb[i] = '0';
	else if (signum == SIGUSR2)
		nb[i] = '1';
	i++;
	if (!identity && i == 8)
	{
		if (bin_to_dec(nb) == ';')
			identity = 1;
		else
			pid = pid * 10 + bin_to_dec(nb) - '0';
		i = 0;
	}
	else if (i == 8)
	{
		norme_detect_signal(nb, &identity, &pid);
		i = 0;
	}
	else if (identity)
		kill(pid, SIGUSR1);
}

int	main(void)
{
	ft_putstr_fd("PID = ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, detect_signal);
	signal(SIGUSR2, detect_signal);
	signal(SIGINT, SIG_IGN);
	while (1)
	{
	}
	return (0);
}
