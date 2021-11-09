/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 00:43:28 by milmi             #+#    #+#             */
/*   Updated: 2021/06/04 19:45:13 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_data
{
	char	*infile;
	int		infd;
	char	**cmd1;
	char	**cmd2;
	char	*outfile;
	int		outfd;
	char	**path;
	char	*pathcmd1;
	char	*pathcmd2;
	int		fd[2];
	int		absolute1;
	int		absolute2;
	int		forkk;
}				t_data;

typedef struct s_temp
{
	char	*path;
	char	*cmdpath;
}				t_temp;

void	free_if(void *var);
void	free_double(char **mem);
void	free_temp(t_temp *temp);
void	free_struct_norm(t_data **data);
void	free_struct(t_data **data);
void	exec_first_cmd(t_data *data, char **envp);
void	exec_second_cmd(t_data *data, char **envp);
int		error_print(t_data *data);
void	init_data(t_data *data);
int		main_norm(char **envp, t_data *data);

#endif
