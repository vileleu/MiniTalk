/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 19:32:29 by vico              #+#    #+#             */
/*   Updated: 2021/09/25 21:53:34 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

int		error_msg(char *msg);

int		bin_to_dec(char *nb);
void	full_zero(char *s);
int		only_zero(char nb[8]);

#endif