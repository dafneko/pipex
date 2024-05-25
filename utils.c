/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:52:37 by dkoca             #+#    #+#             */
/*   Updated: 2024/05/25 05:05:45 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_perror(char *errormsg)
{
    perror(errormsg);
    exit(EXIT_FAILURE);
}

char **find_paths(char **envp)
{
    char *path;
    while (*envp)
    {
        if (!ft_strncmp(*envp, "PATH=", 5))
        {
            path = *envp + 5;
            return (ft_split(path, ':'));     
        }
        envp++;
    }
}


char *ft_strjoin_chr(char *str1, char *str2, char c)
{
    char *bin;
    char *path;
    bin = ft_strjoin(&c, str2);
    path = ft_strjoin(str1, bin);
    free(bin);
    return (path);
}

int check_access(char **envp, char *command)
{
    char **all_paths;
    char *path;
    int found;
    
    all_paths = find_paths(envp);
    while (*all_paths)
    {
        path = ft_strjoin_chr(*all_paths, command, '/');
        if (access(path, F_OK) == 0)
            found = 1;
        all_paths++;
    }
    // free path
}