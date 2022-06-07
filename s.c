/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:39:58 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/06/01 11:19:43 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_straddc_first(char c)
{
	char	*add;

	add = (char *)malloc(sizeof(char) * 2);
	if (!add)
		return (NULL);
	add[0] = c;
	add[1] = '\0';
	return (add);
}

char	*ft_str_add(char *str, char c)
{
	char	*add;
	int		i;

	if (!c)
		return (NULL);
	if (!str)
		return (ft_straddc_first(c));
	add = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!add)
	{
		free(str);
		return (NULL);
	}
	i = -1;
	while (str[++i])
		add[i] = str[i];
	free(str);
	add[i++] = c;
	add[i] = '\0';
	return (add);
}

void	error(int pid, char *msg)
{
	if (msg)
		free(msg);
	kill(pid, SIGUSR2);
	exit(EXIT_FAILURE);
}

char	*print_msg(char *msg)
{
	ft_putstr_fd(msg, 1);
	free(msg);
	return (NULL);
}

void	handler_sigusr(int sig, siginfo_t *info, void *ucontext)
{
	static char	c = 255;
	static int	bits = 0;
	static int	pid = 0;
	static char	*msg = 0;

	(void)ucontext;
	if (info->si_pid)
		pid = info->si_pid;
	if (sig == SIGUSR1)
		c ^= 128 >> bits;
	else if (sig == SIGUSR2)
		c |= 128 >> bits;
	if (++bits == 8)
	{
		if (c)
			msg = ft_str_add(msg, c);
		else
			msg = print_msg(msg);
		bits = 0;
		c = 255;
	}
	if (kill(pid, SIGUSR1) == -1)
		error(pid, msg);
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
