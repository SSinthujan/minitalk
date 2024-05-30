/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:51:15 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/01/31 16:55:21 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bin_to_char(char c)
{
	static char	*str = NULL;

	if (c)
		str = ft_strjoin(str, c);
	else
	{
		ft_printf("%s\n", str);
		free(str);
		str = NULL;
	}
}

void	sig_server(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	cpt_bit = 0;

	if (signum == SIGUSR2)
		c = (c << 1) | 1;
	else if (signum == SIGUSR1)
		c = c << 1;
	if (cpt_bit < 7)
		cpt_bit++;
	else
	{
		bin_to_char(c);
		cpt_bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR2);
	(void)context;
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = sig_server;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
