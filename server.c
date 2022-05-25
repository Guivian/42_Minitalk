/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:39:58 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/05/25 16:44:12 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_sigusr(int signum)
{
	static char	c = 0xFF;
	static int	bits = 0;

	if (signum == SIGUSR1)
	{
		ft_printf("0");
		c ^= 0x80 >> bits;
	}
	else if (signum == SIGUSR2)
	{
		ft_printf("1");
		c |= 0x80 >> bits;
	}
	bits++;
	if (bits == 8)
	{
		ft_printf("-> %c\n", c);
		bits = 0;
		c = 255;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	while (1)
		pause();
}
