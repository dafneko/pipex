/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:47:25 by dkoca             #+#    #+#             */
/*   Updated: 2024/05/25 05:27:00 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include "./libft/libft.h"


#define WRITE 1
#define READ 0
    
typedef struct s_pipex
{
    char **cmd;
    char *infile;
    char *outfile;
    int pipe_end[2];
    char **all_paths;
} t_pipex;

void ft_perror(char *errormsg);
char **find_paths(char **envp);
int get_envp(char **envp, char *command);


#endif 