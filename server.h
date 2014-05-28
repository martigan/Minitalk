/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 16:22:04 by mgaspail          #+#    #+#             */
/*   Updated: 2014/02/08 20:20:09 by mgaspail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define BUFF_SIZE 1024

void	ft_putchar(char c);
int		ft_strlen(char*);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_receive(int sig, siginfo_t *siginfo, void *context);
int		ft_strcmp(const char *str, const char *str2);
char	*ft_strnew(size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_realloc(char*);
void	ft_sigact_init(void);
#endif /* SERVER_H */
