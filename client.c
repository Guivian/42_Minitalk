/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:04:25 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/06/20 18:24:21 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(char *msg, int pid)
{
	int	i;
	int	bitshift;

	i = -1;
	while (msg[++i])
	{
		bitshift = -1;
		while (++bitshift < 8)
		{
			if (msg[i] & (128 >> bitshift))
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(EXIT_FAILURE);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(EXIT_FAILURE);
			}
			usleep(50);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		exit(EXIT_FAILURE);
	send_signal(argv[2], ft_atoi(argv[1]));
	return (0);
}
