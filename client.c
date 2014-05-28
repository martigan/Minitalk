/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:28:12 by mgaspail          #+#    #+#             */
/*   Updated: 2014/02/08 20:18:49 by mgaspail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "client.h"

int		ft_atoi(char *str)
{
	int		nbr;
	int		sign;

	sign = 1;
	nbr = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		sign = (*(str++) == '-' ? -sign : sign);
	while (*str >= '0' && *str <= '9')
		nbr = nbr * 10 + ((*(str++) - '0') * sign);
	return (nbr);
}

int		ft_error(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
	{
		ft_putstr("Usage : ./client PID message\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		ft_putstr("Error : PID must be a strictly positive number.\n");
	return (pid);
}

void	ft_return(int sig, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)sig;
	(void)siginfo;
}

void	ft_signal(char c, int pid)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i++) & 1)
		{
			usleep(50);
			kill(pid, SIGUSR2);
		}
		else
		{
			usleep(50);
			kill(pid, SIGUSR1);
		}
		pause();
	}
}

int		main(int argc, char **argv)
{
	int					pid;
	struct sigaction	act;

	act.sa_sigaction = &ft_return;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	if ((pid = ft_error(argc, argv)) <= 0)
		return (0);
	while (*argv[2] != '\0')
	{
		ft_signal(*argv[2], pid);
		argv[2]++;
	}
	ft_signal(*argv[2], pid);
	return (0);
}
