/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 19:40:03 by vico              #+#    #+#             */
/*   Updated: 2021/09/25 20:32:03 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

int		error_msg(char *msg);

void	full_zero(char *s);
char	*dec_to_bin(int nb);

#endif