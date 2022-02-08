/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 19:39:40 by vico              #+#    #+#             */
/*   Updated: 2021/11/02 18:43:38 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		g_wait_check = 0;

void	wait_answer(void)
{
	while (!g_wait_check)
	{
	}
	g_wait_check = 0;
}

void	norme_send_signal(char *s, int pid, int i, int len)
{
	int	j;

	j = -1;
	while (s[++j])
	{
		if (s[j] == '0')
			kill(pid, SIGUSR1);
		else if (s[j] == '1')
			kill(pid, SIGUSR2);
		if (i <= len)
			usleep(500);
		else
			wait_answer();
	}
}

int	send_signal(int pid, char *send, int len)
{
	int		i;
	char	*s;

	i = -1;
	s = NULL;
	while (1)
	{
		s = dec_to_bin(send[++i]);
		if (!s)
			return (0);
		norme_send_signal(s, pid, i, len);
		free(s);
		if (send[i] == '\0')
			break ;
	}
	return (1);
}

void	wait_check_signal(int signum)
{
	if (signum == SIGUSR1)
		g_wait_check = 1;
}

int	main(int ac, char **av)
{
	int		len;
	int		pid;
	char	*add;

	if (ac != 3)
		return (error_msg("Bad arguments"));
	signal(SIGUSR1, wait_check_signal);
	pid = ft_atoi(av[1]);
	if (kill(pid, SIGINT) == -1)
		return (error_msg("Error : pid doesn't work"));
	add = ft_itoa(getpid());
	len = ft_strlen(add);
	if (!add)
		return (error_msg("Error Malloc"));
	add = ft_strjoin_sp(add, av[2], ';');
	if (!add)
		return (error_msg("Error Malloc"));
	if (!(send_signal(pid, add, len)))
		return (error_msg("Error Malloc"));
	free(add);
	return (0);
}
