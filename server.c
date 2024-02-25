/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:16:01 by akajjou           #+#    #+#             */
/*   Updated: 2024/02/22 16:32:46 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

short	*g_block;

void	handler(int sig)
{
	*(char *)g_block = *(char *)g_block << 1 | (sig == SIGUSR1);
	*(char *)(g_block + 1) += 1;
	if (*(char *)((g_block + 1)) == 8)
	{
		write(1, (char *)g_block, 1);
		*(char *)((g_block + 1)) = 0;
	}
}

int	main(void)
{
	short	g;

	g = 0;
	g_block = &g;
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	ft_printf("THE PID OF THE SERVER is %d\n", getpid());
	while (1)
	{
	}
}
