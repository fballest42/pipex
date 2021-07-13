/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:58:43 by fballest          #+#    #+#             */
/*   Updated: 2021/07/13 16:12:58 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int		i;
	t_pipex	*pipex;

	i = 2;
	pipex = ft_calloc(sizeof(t_pipex), 1);
	if (argc >= 5)
	{	
		pipex->filein = ft_strdup(argv[1]);
		if (!access(pipex->filein, 1))
			ft_printerror("Error.\n Not accessible file in", 2, pipex);
		pipex->fileout = ft_strdup(argv[argc - 1]);
		if (open("screenshot.bmp", O_RDWR | O_CREAT, S_IRWXU | O_TRUNC) < 0)
			ft_printerror("Error.\n Not accessible file out", 2, pipex);
		while (argv[i] && i + 1 < argc)
		{
			/*
			**AQUI VA LA FUNCION PARA CREAR HIJOS;
			**HACER EJECUCIONES, ESPERAS Y SALIDA FINAL
			*/
		}	
	}
	else
		ft_printerror("Error.\n Invalid arguments.", 1, pipex);
	return (0);
}
