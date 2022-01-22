/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 21:46:00 by vaferrei          #+#    #+#             */
/*   Updated: 2022/01/18 03:18:09 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

static char	get_char(char *s, int type_data);
static void	sigusr_handler(int sig_number);
static void	send_message(pid_t pid);
static void	send_null_char(pid_t server_pid);

static void	send_null_char(pid_t server_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		usleep(50);
		kill(server_pid, SIGUSR2);
		i++;
	}
	ft_printf("\033[32;1m**Message was successfully sent**\n\n\033[0m");
	exit(0);
}

static void	send_message(pid_t pid)
{
	unsigned char	c;
	static int		i = 8;
	static pid_t	static_pid;

	if (pid != 0)
		static_pid = pid;
	c = get_char(0, 1);
	if (i == 0)
	{
		i = 8;
		c = get_char(0, 0);
		if (!c)
			send_null_char(static_pid);
	}
	i--;
	if (c >> i & 0x01)
		kill(static_pid, SIGUSR1);
	else if (c)
		kill(static_pid, SIGUSR2);
}

static void	sigusr_handler(int sig_number)
{
	if (sig_number == SIGUSR1)
		ft_printf("\033[0;33m > Sending... \033[0m\n");
	send_message(0);
}

static char	get_char(char *s, int type_data)
{
	static unsigned char	c;
	static char				*str;

	if (type_data == 1)
		return (c);
	if (s)
	{
		str = s;
		c = *str;
	}
	else
		c = *(++str);
	return (c);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("\033[31;1m\n   You need to insert: \033[0m\n");
		ft_printf("\033[33;1m   ./server <PID> <message>\033[0m\n\n", 1);
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	if (pid == 0)
	{
		ft_printf("\033[31;1m\n   PID is not a valid number! \033[0m\n\n");
		exit(0);
	}
	get_char(argv[2], 0);
	signal(SIGUSR1, sigusr_handler);
	signal(SIGUSR2, sigusr_handler);
	send_message(pid);
	while (1)
		pause();
	return (0);
}
