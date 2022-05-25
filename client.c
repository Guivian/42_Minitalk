/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:48:58 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/05/25 16:44:18 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(char *message, int pid)
{
	int	i;
	int	bitshift;

	bitshift = -1;
	i = 0;
	while (message[i])
	{
		while (++bitshift < 8)
		{
			if (message[i] & (0x80 >> bitshift))
			{
				if (kill(pid, SIGUSR2) == -1)
					exit (1);
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					exit (1);
			}
			usleep(3);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		exit(EXIT_FAILURE);
	pid = ft_atoi(argv[1]);
	send_signals(argv[2], pid);
	return (0);
}
