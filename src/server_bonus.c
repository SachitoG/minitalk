/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssenas-y <ssenas-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:57:46 by ssenas-y          #+#    #+#             */
/*   Updated: 2023/11/26 16:42:11 by ssenas-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

void	my_handler(int signum, siginfo_t *info, void *content)
{
	static int	i;
	static char	c;

	(void)content;
	if (signum == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i > 7)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		else
			write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void	finish(int signum)
{
	if (signum == SIGINT)
	{
		ft_printf("\033[0;31m\r[SERVER STOPPED]\n\033[0m");
		exit(0);
	}
}

void	init_sa(struct sigaction *sa)
{
	sigemptyset(&sa->sa_mask);
	sigaddset(&sa->sa_mask, SIGUSR1);
	sigaddset(&sa->sa_mask, SIGUSR2);
	sa->sa_handler = 0;
	sa->sa_flags = SA_SIGINFO;
	sa->sa_sigaction = &my_handler;
}

int	main(void)
{
	struct sigaction	sa;

	init_sa(&sa);
	ft_printf("\033[0;32m[SERVER STARTED]\n\033[0m");
	ft_printf("\033[0;36m[PID: %d]\n\033[0m", getpid());
	if (sigaction(SIGUSR1, &sa, 0) == -1 || sigaction(SIGUSR2, &sa, 0) == -1)
	{
		ft_printf("\033[0;31m\nERROR\n\033[0m");
		return (1);
	}
	signal(SIGINT, finish);
	while (1)
		pause();
	return (0);
}
