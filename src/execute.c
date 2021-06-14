/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:40:08 by agigi             #+#    #+#             */
/*   Updated: 2021/06/14 13:52:55 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_execve(char *cmd)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(1);
}

void	ft_execve(t_data *data, char **argv, char **env)
{
	char	*full_path;
	char	**cmd_argv;

	cmd_argv = ft_split(argv[data->cmd], ' ');
	if (execve(cmd_argv[0], cmd_argv, env) == -1)
	{
		full_path = ft_find_path(data, argv, env);
		if (execve(full_path, cmd_argv, env) == -1)
			ft_error_execve(argv[data->cmd]);
		free(full_path);
	}
	free(cmd_argv);
}

void	ft_execute(t_data *data, char **argv, char **env)
{
	pid_t	cpid;

	cpid = fork();
	if (cpid == 0)
	{
		ft_execve(data, argv, env);
		exit(data->code_ex);
	}
	waitpid(cpid, &data->code_ex, 0);
	if (data->code_ex == 256)
		data->code_ex = 127;
}
