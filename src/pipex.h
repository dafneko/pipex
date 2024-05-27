/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:47:25 by dkoca             #+#    #+#             */
/*   Updated: 2024/05/27 03:21:36 by dkoca            ###   ########.fr       */
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
#include "../libft/libft.h"


#define WRITE_END 1
#define READ_END 0

#define NAME "pipex"

#define CMD_NOT_FOUND "command not found"
#define BAD_FD "Bad file descriptor"
#define PERM_DENIED "Permission denied"
    
typedef struct s_pipex
{
    char **cmd;
    char **envp;
    char *infile;
    char *outfile;
    int pipe_end[2];
    char **all_paths;
    int prev_pid;
} t_pipex;

enum flags
{
    FD_INFILE = 1,
    FD_OUTFILE = 2,
    FD_PIPE_IN = 4,
    FD_PIPE_OUT = 8,
    FD_PREV = 16,
    SAVE_PID = 32
};


void ft_perror(const char *errormsg);
void ft_error(char *errormsg);
void free_double_arr(char **arr);
char *ft_strjoin_chr(char *str1, char *str2, char *c);
char **find_paths(char **envp);
int get_envp(char **envp, char *command);
char *check_access(t_pipex *pipex);
int redirect_output(t_pipex *pipex, int flags);
int redirect_input(t_pipex *pipex, int flags);
void run_pipes(t_pipex *pipex, char **command);
int wait_for_children(t_pipex *pipex);
#endif 