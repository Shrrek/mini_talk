/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:45:58 by jperales          #+#    #+#             */
/*   Updated: 2022/02/23 09:50:50 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int		i;
	int		s;
	long	res;

	i = 0;
	s = 1;
	res = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = s * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		if (res * s < -2147483648 || res * s > 2147483648)
			return ((res * s < -2147483648) - 1);
		i++;
	}
	return (res * s);
}

void	ft_send_bit(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			kill (pid, SIGUSR2);
		else
			kill (pid, SIGUSR1);
		i++;
		usleep(120);
	}
}

int	main(int argc, char	**argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			ft_send_bit(argv[2][i], pid);
			i++;
		}
		ft_send_bit('\n', pid);
		write (1, "Signal received. \n", 18);
	}
	else
	{
		write(1, "Error.\n", 7);
		write(1, "Use: ./client [pid] string \n", 28);
	}
	return (0);
}
