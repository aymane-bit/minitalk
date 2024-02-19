/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:13:36 by akajjou           #+#    #+#             */
/*   Updated: 2024/02/19 11:18:20 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_send_bits(int pid, char c)
{
	int	binaryarray[8];
	int	i;

	i = 7;
	while (i >= 0)
	{
		binaryarray[i] = (c >> i) & 1;
		i--;
	}
	i = 0;
	while (i < 8)
	{
		if (binaryarray[i] == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(50);
		i++;
	}
}

void	ft_receive_handler(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("message well sent.\n");
}

void	ignore_handler(int signum)
{
	if (signum == 0)
	{
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		signal(SIGUSR2, ignore_handler);
		while (argv[2][i] != '\0')
		{
			ft_send_bits(pid, argv[2][i]);
			i++;
		}
		signal(SIGUSR2, ft_receive_handler);
		ft_send_bits(pid, '\n');
	}
	else
	{
		ft_printf("Error: wrong format\n");
		ft_printf("Try: ./client <PID> <MESSAGE>\n");
		return (1);
	}
	return (0);
}
