/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:05:29 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/06/03 14:28:02 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error(int pid)
{
	kill(pid, SIGUSR2);
	exit(EXIT_FAILURE);
}

void	handler_sigusr(int sig, siginfo_t *info, void *ucontext)
{
	static char	c = 255;
	static int	bits = 0;
	static int	pid = 0;

	(void)ucontext;
	if (info->si_pid)
		pid = info->si_pid;
	if (sig == SIGUSR1)
	{
		c |= 128 >> bits;
		ft_printf("0");
	}
	else if (sig == SIGUSR2)
	{
		c ^= 128 >> bits;
		ft_printf("1");
	}
	bits++;
	if (bits == 8)
	{
		ft_printf("%c\n", c);
		bits = 0;
		c = 255;
	}
	if (kill(pid, SIGUSR1) == -1)
		error(pid);
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			block_signal;

	sigemptyset(&block_signal);
	sigaddset(&block_signal, SIGINT);
	sigaddset(&block_signal, SIGQUIT);
	sa.sa_handler = 0;
	sa.sa_mask = block_signal;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler_sigusr;
	ft_printf("PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
