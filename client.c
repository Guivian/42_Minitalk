/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:48:58 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/05/12 20:54:36 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	if (argc > 2)
		exit(EXIT_FAILURE);
	pid = ft_atoi(argv[1]);
	kill(pid, SIGUSR1);
	return (0);
}
