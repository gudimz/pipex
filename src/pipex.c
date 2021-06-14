/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 14:03:17 by agigi             #+#    #+#             */
/*   Updated: 2021/06/14 21:25:40 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_pipe_right(t_data *data, char **argv, char **env)
{
	int	save_fd[2];
	int	fd[2];

	pipe(fd);
	save_fd[0] = dup(0);
	save_fd[1] = dup(1);
	data->fd.std_in = open(argv[1], O_RDONLY);
	if (data->fd.std_in == -1)
	{
		close(data->fd.std_in);
		close(save_fd[0]);
		close(save_fd[1]);
		ft_error_message("Error: could not open infile\n");
	}
	dup2(data->fd.std_in, 0);
	dup2(fd[1], 1);
	ft_execute(data, argv, env);
	data->fd.std_in = fd[0];
	dup2(save_fd[0], 0);
	dup2(save_fd[1], 1);
	close(save_fd[0]);
	close(save_fd[1]);
	close(fd[1]);
}

static void	ft_pipe_left(t_data *data, int argc, char **argv, char **env)
{
	int	save_fd[2];

	save_fd[0] = dup(0);
	save_fd[1] = dup(1);
	dup2(data->fd.std_in, 0);
	data->fd.std_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->fd.std_out == -1)
	{
		close(data->fd.std_out);
		close(data->fd.std_in);
		dup2(save_fd[0], 0);
		dup2(save_fd[1], 1);
		close(save_fd[0]);
		close(save_fd[1]);
		ft_error_message("Error: could not open outfile\n");
	}
	dup2(data->fd.std_out, 1);
	ft_execute(data, argv, env);
	close(data->fd.std_in);
	close(data->fd.std_out);
	dup2(save_fd[0], 0);
	dup2(save_fd[1], 1);
	close(save_fd[0]);
	close(save_fd[1]);
}

static void	ft_pipe_double(t_data *data, char **argv, char **env)
{
	t_descript	save_fd;
	int			fd[2];

	pipe(fd);
	save_fd.std_in = dup(0);
	save_fd.std_out = dup(1);
	dup2(fd[1], 1);
	dup2(data->fd.std_in, 0);
	ft_execute(data, argv, env);
	close(data->fd.std_in);
	dup2(save_fd.std_in, 0);
	dup2(save_fd.std_out, 1);
	close(save_fd.std_in);
	close(save_fd.std_out);
	close(fd[1]);
	data->fd.std_in = fd[0];
}

void	ft_pipex(t_data *data, int argc, char **argv, char **env)
{
	if (data->cmd == 2)
		ft_pipe_right(data, argv, env);
	else if (data->cmd == argc - 2)
		ft_pipe_left(data, argc, argv, env);
	else
		ft_pipe_double(data, argv, env);
}
