/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:48:08 by apylypen          #+#    #+#             */
/*   Updated: 2023/10/07 16:53:03 by apylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	hndlr(int signum, siginfo_t *info, void *context)
{
	static int	client_pid;
	static int	byte;
	static char	c;

	(void)context;
	client_pid = info->si_pid;
	if (signum == SIGUSR1)
	{
		c |= (0x01 << byte);
		byte++;
	}
	else if (signum == SIGUSR2)
		byte++;
	if (byte == 8)
	{
		if (c == 0)
			kill(client_pid, SIGUSR2);
		else
			write(1, &c, 1);
		c = 0;
		byte = 0;
	}
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = hndlr;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
