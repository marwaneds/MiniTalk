/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:03:18 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/02/13 16:06:08 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// 'bit' compte les bits recu (il en faut 8) et 'i' pour stocker les octets
// Si le signal recu est 'SIGUSR1', i est maj en incluant un '1' avec '<<'
// si bit = 8, c'est que l'octets est complet, on l'afiche avec 'ft_printf'
// On remets bit et i a 0 pour le prochain caractere

void	ft_handler(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

// Utilise 'getpid()' pour avoir son pid
// 'signal' pour definir les fonction ft_handler pour recevoir les signaux
// SIGUSR1 et SIGUSR2. Enfin on utilise 'pause()' pour attendre les signaux

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Wrong format\n");
		ft_printf("Use: ./server\n");
		return (0);
	}
	pid = getpid();
	ft_printf("Your PID -> %d\n", pid);
	ft_printf("Waiting for a message...\n");
	while (argc == 1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause ();
	}
	return (0);
}
