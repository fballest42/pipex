/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:58:43 by fballest          #+#    #+#             */
/*   Updated: 2021/11/09 23:10:42 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(char **argv, t_pipex *pipex)
{
	if (!access(argv[1], R_OK))
	{
		pipex->fd_in = open(argv[1], O_RDONLY);
		pipex->file_in = argv[1];
		pipex->fd_out = open(argv[4], O_RDWR | O_CREAT, S_IRWXU | O_APPEND);
		if (pipex->fd_out >= 0)
			pipex->file_out = argv[4];
		else
			ft_printerror("Error:\n", 10, pipex);
	}
	else
		ft_printerror("Error: Not valid files.\n", 3, pipex);
}

void	execute_fork2(int *fd, t_pipex *pipex)
{
	pipex->ph = fork();
	if (pipex->ph == 0)
	{
		dup2(fd[0], 0);
		dup2(pipex->fd_out, 1);
		close(pipex->fd_out);
		execve(pipex->expath2, pipex->cmd_2, pipex->env);
		perror("Error:");
	}
	else if (pipex->ph < 0)
		ft_printerror("Error:\n", 8, pipex);
}

void	execute_fork(t_pipex *pipex)
{
	int		fd[2];
	int		status;

	if (pipe(fd) < 0)
		ft_printerror("Error:\n", 6, pipex);
	pipex->ph = fork();
	if (pipex->ph < 0)
		ft_printerror("Error:\n", 7, pipex);
	else if (pipex->ph == 0)
	{
		dup2(pipex->fd_in, 0);
		dup2(fd[1], 1);
		close(pipex->fd_in);
		execve(pipex->path[pipex->y], pipex->cmd_1, pipex->env);
		perror("Error:");
	}
	else
		execute_fork2(fd, pipex);
	wait(&status);
	wait(&status);
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
		ft_printerror("Error:\n", 1, pipex);

	open_files(argv, pipex);
	pipex->path = add_slash_paths(pipex);
	get_commands(argv, pipex);
	add_command_path(pipex);
	execute_fork(pipex);
	}
	else
		ft_printerror("Error:\n", 2, pipex);
	return (0);
}

// int	take_env(t_pipex *pipex, char **envp)
// {
// 	int		i;

// 	i = 0;
// 	if (!envp)
// 		ft_printerror("Error:\n Not enviroment variable charged.", 1, pipex);
// 	while(envp[i])
// 	{
// 		pipex->env[i] = envp[i];
// 		i++;
// 	}
// 	return (1);
// }

// int	check_files(t_pipex *pipex, int argc, char **argv)
// {
// 	pipex->filein = ft_strdup(argv[1]);
// 	if (!access(pipex->filein, 1))
// 		ft_printerror("Error.\n Not accessible file in", 3, pipex);
// 	pipex->fileout = ft_strdup(argv[argc - 1]);
// 	if (open(pipex->fileout, O_RDWR | O_CREAT, S_IRWXU | O_TRUNC) < 0)
// 		ft_printerror("Error.\n Not accessible file out", 4, pipex);
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	int		i;
// 	t_pipex	*pipex;

// 	i = 2;
// 	pipex = ft_calloc(sizeof(t_pipex), 1);
// 	if (!pipex)
// 		ft_printerror("Error\n Not Memory Reserved, 2, pipex");
// 	if (argc >= 5)
// 	{
// 		take_env(pipex, envp);
// 		check_files(pipex, argc, argv);
		
// 		while (argv[i] && i < argc)
// 		{
// 			pipex->cmd[i - 2] = ft_split(argv[i], " ");
// 			pipex->pn = fork();
// 			i++;
// 		}	
// 	}
// 	else
// 		ft_printerror("Error.\n Invalid arguments.", 1, pipex);
// 	return (0);
// }
