/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:16:12 by akajjou           #+#    #+#             */
/*   Updated: 2024/02/22 16:37:23 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_bits(int pid, char c)
{
	int		i;
	char	s;

	i = 7;
	while (i >= 0)
	{
		s = c >> i & 1;
		if (s == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc != 3)
	{
		ft_printf("PLEASE ENTER THE SERVER PID AND THE MESSAGE TO SEND\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
		ft_send_bits(pid, argv[2][i++]);
}
