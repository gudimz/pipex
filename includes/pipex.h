/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 00:33:44 by agigi             #+#    #+#             */
/*   Updated: 2021/06/13 01:33:34 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/stat.h>

typedef struct s_descript
{
	int	std_in;
	int	std_out;
}				t_descript;

typedef struct s_data
{
	t_descript	fd;
	int			code_ex;
	int			cmd;
}				t_data;

char	*ft_find_path(t_data *data, char **argv, char **env);
void	ft_pipex(t_data *data, int argc, char **argv, char **env);
void	ft_error_message(char *message);
void	ft_execute(t_data *data, char **argv, char **env);

#endif
