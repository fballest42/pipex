/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:01:14 by fballest          #+#    #+#             */
/*   Updated: 2021/11/05 11:05:27 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*
**LIBRARIES
*/
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include "libft/libft.h"

/*
**WORKING STRUCTURES
*/
typedef struct s_pipex
{
	int		x;
	int		y;
	int		fd_in;
	int		fd_out;
	char	*file_in;
	char	*file_out;
	char	**cmd_1;
	char	**cmd_2;
	char	**env;
	char	**path;
	char	*expath;
	char	*expath2;
	pid_t	ph;
}				t_pipex;

/*
**FILES AND FUNTIONS
*/
/*
**PIPEXMAIN
*/
char		**take_envs(char **env, t_pipex *pipex);
void		get_commands(char **argv, t_pipex *pipex);
void		check_path(t_pipex *pipex);
void		open_files(char **argv, t_pipex *pipex);
int			main (int argc, char **argv, char **env);

/*
**PARSER.C
*/
void		ft_printerror(char *str, int error, t_pipex *pipex);
char		**add_slash_paths(t_pipex *pipex);
void		add_command_path(t_pipex *pipex);

#endif
