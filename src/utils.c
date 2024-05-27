/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:52:37 by dkoca             #+#    #+#             */
/*   Updated: 2024/05/27 03:15:17 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_perror(const char *program)
{
    perror(program);
    exit(EXIT_FAILURE);
}

void ft_error(char *errormsg)
{
    ft_putendl_fd(errormsg, STDERR_FILENO);
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

void free_double_arr(char **arr)
{
    int i;

    i = -1;
    while (arr[++i])
        free(arr[i]);
    free(arr);
}