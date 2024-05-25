/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:46:53 by dkoca             #+#    #+#             */
/*   Updated: 2024/05/25 05:21:34 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void init_pipex(t_pipex *pipex, int ac, char *command, char *envp[])
{
    pipex->infile = command[1];
    pipex->outfile = command[ac - 1];
    pipex->all_paths = find_paths(envp);
}

int  main(int ac, char *argv[], char *envp[])
{
    t_pipex *pipex;
    
    // char *command[] = {"grep", "-e", "c$", "-", "|", "cat", "-" 0};
    char *command[] = {"grep -e c$ -" "cat -", 0};
    init_pipex(pipex, ac, command, envp);
    
}