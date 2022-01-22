/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:08:15 by vaferrei          #+#    #+#             */
/*   Updated: 2022/01/22 14:30:29 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

static void	sigusr_handler(int sig_number, siginfo_t *sig_info, void *p);
static void	receive_message(int sig_number, pid_t pid);

static void	receive_message(int sig_number, pid_t pid)
{
	static unsigned char	c = 0x00;
	static int				i = 0;

	i++;
	if (sig_number == SIGUSR1)
		c = c | 1;
	if (i == 8)
	{
		i = 0;
		if (c == 0x00)
			return ;
		ft_printf("%c", c);
		c = 0x00;
		kill(pid, SIGUSR1);
	}
	else
	{
		c = c << 1;
		kill(pid, SIGUSR2);
	}
}

static void	sigusr_handler(int sig_number, siginfo_t *sig_info, void *p)
{
	pid_t	pid;

	(void)p;
	pid = sig_info->si_pid;
	receive_message(sig_number, pid);
}

int	main(void)
{
	struct sigaction	info;

	ft_printf("\n \033[0;33m PID: %d \033[0m\n", getpid());
	info.sa_flags = SA_SIGINFO;
	info.sa_sigaction = sigusr_handler;
	sigaction(SIGUSR1, &info, 0);
	sigaction(SIGUSR2, &info, 0);
	while (1)
		pause();
	return (0);
}
