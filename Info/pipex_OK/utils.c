/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 19:22:21 by milmi             #+#    #+#             */
/*   Updated: 2021/06/05 12:43:48 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_first_cmd(t_data *data, char **envp)
{
	dup2(data->infd, 0);
	dup2(data->fd[1], 1);
	close(data->infd);
	execve(data->pathcmd1, data->cmd1, envp);
	perror("Error");
}

void	exec_second_cmd(t_data *data, char **envp)
{
	dup2(data->fd[0], 0);
	dup2(data->outfd, 1);
	close(data->outfd);
	execve(data->pathcmd2, data->cmd2, envp);
	perror("Error");
}

int	error_print(t_data *data)
{
	perror("Error");
	free_struct(&data);
	free(data);
	return (1);
}

void	init_data(t_data *data)
{
	data->absolute1 = 0;
	data->absolute2 = 0;
	data->cmd1 = NULL;
	data->cmd2 = NULL;
	data->infd = 0;
	data->infile = NULL;
	data->outfd = 0;
	data->outfile = NULL;
	data->path = NULL;
	data->pathcmd1 = NULL;
	data->pathcmd2 = NULL;
}

int	main_norm(char **envp, t_data *data)
{
	data->forkk = fork();
	if (data->forkk == 0)
		exec_second_cmd(data, envp);
	else if (data->forkk == -1)
		return (error_print(data));
	return (0);
}
