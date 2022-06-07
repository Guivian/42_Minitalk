/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:48:58 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/06/01 10:45:32 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error(char *msg)
{
	if (msg)
		free(msg);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

int	send_null(int pid, char *msg)
{
	static int	i = 0;

	if (i++ != 8)
	{
		if (kill(pid, SIGUSR1 == -1))
			error(msg);
		return (0);
	}
	return (1);
}

int	send_bits(char *message, int pid)
{
	static char	*msg = NULL;
	static int	bitshift = -1;
	static int	s_pid = 0;

	if (message)
		msg = ft_strdup(message);
	if (!msg)
		error(0);
	if (pid)
		s_pid = pid;
	if (message[++bitshift / 8])
	{
		if (message[bitshift / 8] & (128 >> (bitshift % 8)))
		{
			if (kill(s_pid, SIGUSR2) == -1)
				error(msg);
		}
		else if (kill(s_pid, SIGUSR1) == -1)
			error(msg);
		return (0);
	}
	if (!send_null(s_pid, msg))
		return (0);
	free(msg);
	return (1);
}

void	handler_sigusr(int sig)
{
	int	success;

	success = 0;
	if (sig == SIGUSR1)
		success = send_bits(NULL, 0);
	else if (sig == SIGUSR2)
		exit (EXIT_FAILURE);
	if (success == 1)
		exit (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		exit(EXIT_FAILURE);
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	send_bits(argv[2], ft_atoi(argv[1]));
	while (1)
		pause();
}
