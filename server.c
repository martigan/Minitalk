/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:03:39 by mgaspail          #+#    #+#             */
/*   Updated: 2014/02/08 19:52:30 by mgaspail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "server.h"

static char		*ft_printfree(char *buf, int *i)
{
	buf[*i] = '\n';
	write(1, buf, *i + 1);
	free(buf);
	*i = 0;
	return (NULL);
}

static char		*ft_realfree(char *buf, int i)
{
	char	*tmp;

	buf[i] = '\0';
	tmp = ft_realloc(buf);
	free(buf);
	buf = tmp;
	return (buf);
}

static void		ft_print(int signum)
{
	static int		bit = 0;
	static char		c = 0;
	static int		i = 0;
	static char		*buf = NULL;

	if (buf == NULL)
		buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (signum == SIGUSR2)
		c = c | (1 << bit);
	if (bit == 7)
	{
		if (i != 0 && i % BUFF_SIZE == 0)
			buf = ft_realfree(buf, i);
		if (c == 0)
			buf = ft_printfree(buf, &i);
		else
			buf[i++] = c;
		c = 0;
		bit = 0;
	}
	else
		bit++;
}

void			ft_receive(int sig, siginfo_t *siginfo, void *context)
{
	usleep(100);
	(void)context;
	ft_print(sig);
	kill(siginfo->si_pid, SIGUSR1);
}

int				main(void)
{
	int		pid;

	pid = getpid();
	ft_putstr("PID : ");
	ft_putnbr(pid);
	ft_putchar('\n');
	while (1)
	{
		ft_sigact_init();
		pause();
	}
	return (0);
}
