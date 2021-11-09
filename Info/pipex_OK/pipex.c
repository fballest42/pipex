/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 19:24:11 by milmi             #+#    #+#             */
/*   Updated: 2021/06/05 13:00:01 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_cmd(char **pathcmd, t_data *data, char *cmd)
{
	t_temp	*temp;
	int		cmd1fd;
	int		i;

	i = 0;
	temp = malloc(sizeof(t_temp));
	while (data->path[i])
	{
		temp->path = ft_strjoin(data->path[i], "/");
		temp->cmdpath = ft_strjoin(temp->path, cmd);
		cmd1fd = open(temp->cmdpath, O_RDONLY);
		if (cmd1fd > 0)
		{
			*pathcmd = ft_strdup(temp->cmdpath);
			free_temp(temp);
			free(temp);
			return (1);
		}
		free_temp(temp);
		i++;
	}
	free(temp);
	return (0);
}

int	check_data(t_data *data)
{
	data->infd = open(data->infile, O_RDWR);
	if (data->infd < 0)
		return (1);
	data->outfd = open(data->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (data->outfd < 0)
		return (1);
	if (data->absolute1 == 0)
	{
		if (!check_cmd(&data->pathcmd1, data, data->cmd1[0]))
			return (10);
	}
	else
		data->pathcmd1 = ft_strdup(data->cmd1[0]);
	if (data->absolute2 == 0)
	{
		if (!check_cmd(&data->pathcmd2, data, data->cmd2[0]))
			return (10);
	}
	else
		data->pathcmd2 = ft_strdup(data->cmd2[0]);
	return (0);
}

char	*find_path(char **envp)
{
	char	**path;
	char	*ret;
	int		i;

	i = 0;
	while (envp[i])
	{
		path = ft_split(envp[i], '=');
		if (!ft_strncmp("PATH", path[0], 5))
		{
			ret = ft_strdup(path[1]);
			free_double(path);
			return (ret);
		}
		i++;
		free_double(path);
	}
	return (NULL);
}

int	parse_data(t_data **data, char **argv, char **envp)
{
	char	*pathenv;
	char	*temp;

	(*data)->infile = ft_strdup(argv[1]);
	temp = ft_strdup(argv[2]);
	(*data)->cmd1 = ft_split(temp, ' ');
	if (ft_strncmp(temp, "/", 1) == 0
		|| ft_strncmp(temp, "./", 2) == 0 || ft_strncmp(temp, "../", 3) == 0)
		(*data)->absolute1 = 1;
	free(temp);
	temp = ft_strdup(argv[3]);
	(*data)->cmd2 = ft_split(temp, ' ');
	if (ft_strncmp(temp, "/", 1) == 0
		|| ft_strncmp(temp, "./", 2) == 0 || ft_strncmp(temp, "../", 3) == 0)
		(*data)->absolute2 = 1;
	free (temp);
	(*data)->outfile = ft_strdup(argv[4]);
	pathenv = find_path(envp);
	if (pathenv == NULL
		&& ((*data)->absolute1 == 0 || (*data)->absolute2 == 0))
		return (-1);
	(*data)->path = ft_split(pathenv, ':');
	free(pathenv);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	if (argc == 5)
	{
		data = malloc(sizeof(t_data));
		init_data(data);
		if (pipe(data->fd) != 0)
			return (error_print(data));
		if (parse_data(&data, argv, envp) == -1)
			return (write(1, "Error: PATH varriable is missing!\n", 34));
		if (check_data(data))
			return (error_print(data));
		data->forkk = fork();
		if (data->forkk == 0)
			exec_first_cmd(data, envp);
		else if (data->forkk == -1)
			return (error_print(data));
		if (main_norm(envp, data))
			return (1);
		free_struct(&data);
		free(data);
	}
	else
		write(2, "Syntax error\n", 13);
	return (0);
}
