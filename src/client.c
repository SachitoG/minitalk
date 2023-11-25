/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssenas-y <ssenas-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:57:36 by ssenas-y          #+#    #+#             */
/*   Updated: 2023/11/25 21:39:31 by ssenas-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_atoi(const char *str)
{
	long	nbr;
	long	tmp;
	int		i;

	nbr = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		tmp = nbr;
		nbr = (nbr * 10) + (str[i] - '0');
		if (nbr < tmp)
			return (0);
		i++;
	}
	return (nbr);
}

void	send_char(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(100);
	}
}

void	send_str(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(str[i], pid);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("usage: ./client <pid> <message>\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid == 0)
	{
		ft_printf("PID invalid. PID must only contain digits, ");
		ft_printf("be positive and greater than 0\n");
		return (0);
	}
	for (int i = 0; i < 100; i++)
	{
		send_str(argv[2], pid);
		send_char('\n', pid);
	}
	return (0);
}
