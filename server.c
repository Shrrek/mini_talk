/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:53:15 by jperales          #+#    #+#             */
/*   Updated: 2022/01/21 18:58:42 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
			write (1, "-", 1);
		if (n > 9)
			ft_putnbr((n / 10));
		ft_putchar((n % 10) + '0');
	}
}

void	ft_signal_handler(int signal)
{
	static int	exp;
	static int	c;
	static int	bit;

	if (!c || bit == 8)
		c = 0;
	if (!bit || bit == 8)
		bit = 0;
	if (!exp || bit == 0)
		exp = 1;
	if (signal == SIGUSR2)
		c = c + exp;
	bit++;
	exp = exp * 2;
	if (bit == 8)
		write(1, &c, 1);
	if (bit == 8 && !c)
		write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	if (argc != 1)
	{
		write (1, "Error.\n", 7);
		write (1, "Run the server without arguments: ./server\n", 43);
		exit (0);
	}
	pid = getpid();
	write (1, "This is the PID: \n", 18);
	ft_putnbr (pid);
	write (1, "\n", 1);
	while (argc == 1)
	{
		signal (SIGUSR1, ft_signal_handler);
		signal (SIGUSR2, ft_signal_handler);
		pause ();
	}
	return (0);
}
