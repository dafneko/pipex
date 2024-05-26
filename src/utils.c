/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:52:37 by dkoca             #+#    #+#             */
/*   Updated: 2024/05/26 07:25:15 by dkoca            ###   ########.fr       */
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
    return (NULL);
}


char *ft_strjoin_chr(char *str1, char *str2, char *c)
{
    char *bin;
    char *path;
    (void)c;
    bin = ft_strjoin(c, str2);
    path = ft_strjoin(str1, bin);
    free(bin);
    return (path);
}

char *check_access(t_pipex *pipex)
{
    char *path;
    int found; 
    int i;
    
    i = 0;
    found = 0;
    while (pipex->all_paths[i])
    {
        path = ft_strjoin_chr(pipex->all_paths[i], *(pipex->cmd), "/");
        // printf("path = %s\n", path);
        if (access(path, F_OK) == 0)
            found = 1;
        if (access(path, X_OK) == 0)
            break;
        free(path);
        i++;
        // (*pipex->all_paths)++;
    }
    if (path && found)
        return (path);   
    else if(found)
        ft_perror("Permission denied.\n");
    else
        ft_perror("Command not found\n");
    return (NULL);     
}