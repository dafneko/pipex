/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:59:57 by dkoca             #+#    #+#             */
/*   Updated: 2024/05/25 05:27:23 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int redirect_input()
{
    
}

int redirect_output()
{
    
}

void create_child_process(t_pipex *pipex, char *command)
{
    pid_t pid;
    
    pid = fork();
    if (pid == -1)
        ft_perror("Fork failed.");
    if (pid == 0)
    {
        pipex->cmd = ft_split(command, ' ');
        
    }
}