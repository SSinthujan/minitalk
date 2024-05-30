/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:52:40 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/01/31 16:54:52 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_ok;

void	char_to_bin(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_ok = 0;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit--;
		while (!g_ok)
			pause();
	}
}

void	send_signal(int pid, char *str)
{
	int	i;

	i = 0;
	while (i <= ft_strlen(str))
		char_to_bin(pid, str[i++]);
}

void	sig_client(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signum == SIGUSR2)
		g_ok = 1;
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = sig_client;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (ac == 3)
	{
		if (!av[1][0] || !av[2][0])
		{
			ft_printf("Erreur argument\n");
			exit(1);
		}
		if (ft_atoi(av[1]) <= 0 || kill(ft_atoi(av[1]), 0))
		{
			ft_printf("Erreur PID\n");
			exit(1);
		}
		send_signal(ft_atoi(av[1]), av[2]);
	}
	else
		ft_printf("Erreur syntaxe\n");
	return (0);
}
