/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:05:09 by dkoca             #+#    #+#             */
/*   Updated: 2024/05/30 10:34:02 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_double_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	free_pipex(t_pipex *pipex)
{
	if (pipex->all_paths)
		free_double_arr(pipex->all_paths);
	if (pipex->cmd)
		free_double_arr(pipex->cmd);
	free(pipex);
}
