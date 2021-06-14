/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:43:42 by agigi             #+#    #+#             */
/*   Updated: 2021/06/14 21:25:59 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**ft_full_path(t_data *data, char **argv, char **all_path)
{
	char	*tmp;
	char	**name_cmd;
	int		i;

	i = 0;
	name_cmd = ft_split(argv[data->cmd], ' ');
	while (all_path[i])
	{
		tmp = all_path[i];
		all_path[i] = ft_strjoin(all_path[i], "/");
		free(tmp);
		tmp = all_path[i];
		all_path[i] = ft_strjoin(all_path[i], name_cmd[0]);
		free(tmp);
		i++;
	}
	free(name_cmd);
	return (all_path);
}

static char	**ft_init_path(t_data *data, char **argv, char **env)
{
	char	**all_path;
	char	*tmp;
	int		i;
	int		n;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			tmp = env[i];
		i++;
	}
	n = 5;
	while (n--)
		tmp++;
	all_path = ft_split(tmp, ':');
	all_path = ft_full_path(data, argv, all_path);
	return (all_path);
}

static char	*ft_one_path(char **all_path)
{
	int			i;
	char		*path;
	struct stat	buf;

	i = 0;
	path = NULL;
	while (all_path[i])
	{
		if (!stat(all_path[i], &buf))
			path = ft_strdup(all_path[i]);
		i++;
	}
	return (path);
}

char	*ft_find_path(t_data *data, char **argv, char **env)
{
	char	**all_path;
	char	*one_path;

	all_path = ft_init_path(data, argv, env);
	one_path = ft_one_path(all_path);
	if (one_path == NULL)
		return (argv[data->cmd]);
	return (one_path);
}
