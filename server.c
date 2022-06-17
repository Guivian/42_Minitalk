/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:10:49 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/06/14 19:58:23 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_sigusr(int signum)
{
	static char	c = 0xFF;
	static int	bits = 0;

	if (signum == SIGUSR1)
	{
		ft_printf("1");
		c |= 128 >> bits;
	}
	else if (signum == SIGUSR2)
		ft_printf("0");
}

int	main(void)
{
	ft_printf("PID: %i\n", getpid());
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	while (1)
		pause();
}
