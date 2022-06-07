/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:12:24 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/06/03 14:38:55 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error(char *msg)
{
	if (msg)
		free(msg);
	exit(EXIT_FAILURE);
}

int	send_null(int pid, char *str)
{
	static int	i = 0;

	if (i++ != 8)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_printf("Erro send_nul\n");
			error(str);
		}
		return (0);
	}
	return (1);
}

int	send_signal(char *msg, int pid)
{
	static int	bitshift = -1;
	static int	static_pid = 0;
	static char	*static_msg = 0;

	if (msg)
		static_msg = ft_strdup(msg);
	if (!static_msg)
	{
		ft_printf("Erro !msg\n");
		error(0);
	}
	if (pid)
		static_pid = pid;
	if (static_msg[++bitshift / 8])
	{
		if (++bitshift < 8)
		{
			if (static_msg[bitshift / 8] & (128 >> bitshift % 8))
			{
				if (kill(static_pid, SIGUSR1) == -1)
				{
					ft_printf("Erro send_signal signal: 0\n");
					error(static_msg);
				}
				ft_printf("0");
			}
			else
			{
				if (kill(static_pid, SIGUSR2) == -1)
				{
					ft_printf("Erro send_signal signal: 1\n");
					error(static_msg);
				}
				ft_printf("1");
			}
			return (0);
		}
	}
	if (!send_null(static_pid, static_msg))
		return (0);
	free(static_msg);
	return (1);
}

void	handler_sigusr(int sig)
{
	int	success;

	success = 0;
	if (sig == SIGUSR1)
		success = send_signal(0, 0);
	else if (sig == SIGUSR2)
		exit(EXIT_FAILURE);
	if (success)
		exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		exit(EXIT_FAILURE);
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	send_signal(argv[2], ft_atoi(argv[1]));
	while (1)
		pause();
}
