/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 04:54:37 by dkoca             #+#    #+#             */
/*   Updated: 2024/05/26 07:42:15 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void open_infile(char *infile, int *fd)
{
    if (access(infile, F_OK) == -1)
        ft_perror("No such file or directory.");
    if (access(infile, R_OK) == 0)
    {
        *fd = open(infile, O_RDONLY);
        if (*fd == -1)
            ft_perror("Open failed.");
    }
    else
        ft_perror("Permission denied.");
}

void open_outfile(char *outfile, int *fd)
{
    if (access(outfile, W_OK) == 0)
    {
        *fd = open(outfile, O_CREAT | O_TRUNC | O_WRONLY, 0644);
        if (*fd == -1)
            ft_perror("Open failed.");
    }
    else
    ft_perror("Permission denied.");
}

int redirect_input(t_pipex *pipex, int flags)
{
    int fd;

    fd = STDIN_FILENO;
    if ((FD_PIPE_IN & flags) == 0)
        close(pipex->pipe_end[READ_END]);
    if (FD_INFILE & flags)
        open_infile(pipex->infile, &fd);
    else if (FD_PIPE_IN & flags)
        fd = pipex->pipe_end[READ_END];
    if (fd != STDIN_FILENO)
    {
        if (dup2(fd, STDIN_FILENO) == -1)
            (close(fd), ft_perror("Bad file descriptor.\n"));
        close(fd);
    }
    return (EXIT_SUCCESS);
}

int redirect_output(t_pipex *pipex, int flags)
{
    int fd;
    
    fd = STDOUT_FILENO;
    if ((FD_PIPE_OUT & flags) == 0)
        close(pipex->pipe_end[WRITE_END]);
    if (FD_OUTFILE & flags)
        open_outfile(pipex->outfile, &fd);
    else if (FD_PIPE_OUT & flags)
        fd = pipex->pipe_end[WRITE_END];
    if (fd != STDOUT_FILENO)
    {
        if (dup2(fd, STDOUT_FILENO) == -1)
            (close(fd), ft_perror("Bad file descriptor."));
        // close(fd);
    }
    return (EXIT_SUCCESS);    
}