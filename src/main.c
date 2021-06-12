/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 01:32:13 by agigi             #+#    #+#             */
/*   Updated: 2021/06/13 01:34:27 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_message(char *message)
{
	ft_putstr_fd(message, 2);
	exit(1);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc < 5)
		ft_error_message("Error: wrong number of arguments\n");
	ft_bzero(&data, sizeof(t_data));
	data.cmd = 2;
	while (data.cmd < argc - 1)
	{
		if (data.code_ex == 127)
		{
			close(data.fd.std_in);
			exit(1);
		}
		ft_pipex(&data, argc, argv, env);
		data.cmd++;
	}
	return (data.code_ex);
}
