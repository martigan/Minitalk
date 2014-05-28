/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:23:17 by mgaspail          #+#    #+#             */
/*   Updated: 2014/02/08 13:20:53 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp)
		tmp++;
	return (tmp - str);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	else
		n = -n;
	if (n > -10)
		ft_putchar(-n + '0');
	else
	{
		ft_putnbr(-n / 10);
		ft_putnbr(-n % 10);
	}
}

int		ft_strcmp(const char *str, const char *str2)
{
	unsigned char*_str;
	unsigned char*_str2;

	_str = (unsigned char*) str;
	_str2 = (unsigned char*) str2;
	while (*_str != '\0' && *_str2 != '\0' && *_str == *_str2)
	{
		_str++;
		_str2++;
	}
	return (*_str - *_str2);
}
