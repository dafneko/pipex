/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:46:53 by dkoca             #+#    #+#             */
/*   Updated: 2024/05/30 10:34:12 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipex(t_pipex *pipex, char **command, char *envp[])
{
	pipex->envp = envp;
	pipex->infile = command[1];
	pipex->outfile = command[4];
	pipex->all_paths = find_paths(envp);
	if (!pipex->all_paths)
		ft_perror(NAME, pipex);
}

int	main(int ac, char *argv[], char *envp[])
{
	t_pipex	*pipex;

	if (ac != 5)
		ft_error("Invalid argument count");
	pipex = ft_calloc(1, sizeof(t_pipex));
	init_pipex(pipex, argv, envp);
	run_pipes(pipex, argv);
	return (wait_for_children(pipex));
}
