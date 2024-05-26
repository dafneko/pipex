/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:46:53 by dkoca             #+#    #+#             */
/*   Updated: 2024/05/26 07:30:22 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void init_pipex(t_pipex *pipex, char **command, char *envp[])
{
    pipex->envp = envp;
    pipex->infile = command[1];
    pipex->outfile = command[4];
    pipex->all_paths = find_paths(envp);
    pipex->cmd = command;
    if (!pipex->all_paths)
        ft_perror("Command not found.\n");
    pipex->fd_in = -1;
    pipex->fd_out = -1;
}

int  main(int ac, char *argv[], char *envp[])
{
    t_pipex *pipex;
    
    if (ac != 5)
        ft_perror("Invalid arguments.\n");
    // printf("HERE\n");
    // (void)argv;
    pipex = ft_calloc(1, sizeof(t_pipex));
    // char *command[] = {"grep", "-e", "c$", "-", "|", "cat", "-" 0};
    // char *command[] = {"infile.txt", "grep -e c$ -", "cat -", "outfile.txtp", 0};
    init_pipex(pipex, argv, envp);
    run_pipes(pipex, argv);
    return (wait_for_children(pipex));
}