/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:04:25 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/06/14 19:55:47 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(char *msg, int pid)
{
	int	i;
	int	bitshift;

	bitshift = -1;
	i = -1;
	while (msg[++i])
	{
		while (++bitshift < 8)
		{
			if (msg[i] & 128 >> bitshift)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
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
