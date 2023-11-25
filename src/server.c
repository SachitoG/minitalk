/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssenas-y <ssenas-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:57:46 by ssenas-y          #+#    #+#             */
/*   Updated: 2023/11/25 17:59:25 by ssenas-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

void	my_handler(int signum)
{
	static int	i;
	static char	c;

	if (signum == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i > 7)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void	finish(int signum)
{
	if (signum == SIGINT)
	{
		ft_printf("\033[0;31m\n[server closed]\n\033[0m");
		exit(0);
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("\033[0;32m[server started]\n\033[0m");
	ft_printf("\033[0;36m[pid : %d]\n\033[0m", getpid());
	sa.sa_handler = my_handler;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &sa, 0) == -1 || sigaction(SIGUSR2, &sa, 0) == -1)
	{
		ft_printf("\nERROR\n");
		return (1);
	}
	signal(SIGINT, finish);
	while (1)
		pause();
	return (0);
}
