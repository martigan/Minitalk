/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 11:17:44 by rgary             #+#    #+#             */
/*   Updated: 2014/02/08 18:32:07 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "server.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	char			*tmp;
	unsigned char	ch;

	i = 0;
	tmp = (char*)b;
	ch = (unsigned char)c;
	while (len > 0)
	{
		tmp[i] = ch;
		i++;
		len--;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

char	*ft_strnew(size_t size)
{
	char	*mem;

	mem = (char*)malloc(sizeof(char) * (size + 1));
	if (!mem)
		return (NULL);
	ft_bzero(mem, size + 1);
	return (mem);
}

char	*ft_realloc(char *buf)
{
	int		i;
	char	*tmp;

	i = ft_strlen(buf) + BUFF_SIZE + 1;
	if ((tmp = (char *)malloc(sizeof(char) * i)) == NULL)
	{
		write(1, "AAAAAAH\n", 8);
	}
	i = 0;
	while (buf[i])
	{
		tmp[i] = buf[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
