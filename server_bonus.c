/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:14:02 by akajjou           #+#    #+#             */
/*   Updated: 2024/02/19 11:00:23 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile int	g_sender_pid;

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;

	context += 0;
	g_sender_pid = info->si_pid;
	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
		kill(g_sender_pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	pid = getpid();
	ft_printf("PID -> %d\n", pid);
	ft_printf("Waiting for a message...\n");
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause ();
	}
	return (0);
}
