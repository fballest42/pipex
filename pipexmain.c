/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:58:43 by fballest          #+#    #+#             */
/*   Updated: 2021/12/01 00:09:05 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(char **argv, t_pipex *pipex)
{
	pipex->file_in = argv[1];
	pipex->file_out = argv[4];
	pipex->fd_in = open(pipex->file_in, O_RDONLY);
	if (pipex->fd_in <= 0)
	{
		perror(("pipex"));
		exit (errno);
	}
	pipex->fd_out = open(pipex->file_out, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->fd_out < 0)
	{
		perror(("pipex"));
		exit (errno);
	}
}

void	execute_fork2(int *fd, t_pipex *pipex)
{
	int		status;

	pipex->ph = fork();
	if (pipex->ph < 0)
	{
		perror("pipex");
		exit (errno);
	}
	if (pipex->ph == 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		dup2(pipex->fd_out, 1);
		close(pipex->fd_in);
		if (execve(pipex->expath2, pipex->cmd_2, pipex->env))
		{
			perror("pipex");
			exit (errno);
		}
	}
	close(fd[0]);
	close(fd[1]);
	close(pipex->fd_out);
	wait(&status);
	wait(&status);
}

void	execute_fork(t_pipex *pipex)
{
	int		fd[2];

	if (pipe(fd) < 0)
	{
		perror("pipex");
		exit (errno);
	}
	pipex->ph = fork();
	if (pipex->ph < 0)
	{
		perror("pipex");
		exit (errno);
	}
	if (pipex->ph == 0)
	{
		close(fd[0]);
		dup2(pipex->fd_in, 0);
		dup2(fd[1], 1);
		close(fd[1]);
		if (execve(pipex->expath, pipex->cmd_1, pipex->env))
		{
			perror("pipex");
			exit (errno);
		}
	}
	execute_fork2(fd, pipex);
}

int	main (int argc, char **argv, char **env)
{
	t_pipex		*pipex;

	pipex = NULL;
	if (argc == 5)
	{
		pipex = ft_calloc(sizeof(t_pipex), 1);
		take_envs(env, pipex);
		if (!pipex || !pipex->env || argc < 5)
		{
			perror("pipex");
			return (errno);
		}
		open_files(argv, pipex);
		pipex->path = add_slash_paths(pipex);
		get_commands(argv, pipex);
		add_command_path(pipex);
		execute_fork(pipex);
	}
	else
	{
		perror("pipex");
		return (1);
	}
	return (0);
}
