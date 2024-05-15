/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:05:47 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/02/13 16:53:54 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// chaque caractere est representer par 8 bits
// chaque bits est comparer (grace a l'operateur "&") à 0x01 (1) Si le resultat
// vaut 0, SIGUSR2 est envoye au client, sinon SIGUSR1 le sera
// Apres cela, "<<" deplacera les bits de 1 'rang' vers la droite
// On utilise usleep(100) pour marquer un temps d'arret pour que l'envoie du
// signal ce passe correctement

void	ft_send_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

//Verifie si il y a bien 3 arguments ./client <PID> <MESSAGE>
//convertir le PID en entier
//Chaque caractere est pris en charge par ft_send_bits

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_send_bits(pid, argv[2][i]);
			i++;
		}
		ft_send_bits(pid, '\n');
		ft_printf("Message bien envoyé\n");
	}
	else
	{
		ft_printf("Wrong format\n");
		ft_printf("Use: ./client <PID> <MESSAGE>\n");
		return (1);
	}
	return (0);
}
