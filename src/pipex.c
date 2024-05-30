/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:59:57 by dkoca             #+#    #+#             */
/*   Updated: 2024/05/30 10:25:41 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_access(t_pipex *pipex)
{
	char	*path;
	int		found;
	int		i;

	i = 0;
	found = 0;
	while (pipex->all_paths[i])
	{
		path = ft_strjoin_chr(pipex->all_paths[i], *(pipex->cmd), "/");
		if (access(path, F_OK) == 0)
			found = 1;
		if (access(path, X_OK) == 0)
			break ;
		free(path);
		i++;
	}
	if (path && found)
		return (path);
	else if (found)
		ft_perror(NAME, pipex);
	else
		ft_perror(NAME, pipex);
	return (NULL);
}

void	execute(t_pipex *pipex)
{
	char	*bin;

	bin = check_access(pipex);
	if (bin)
		if (execve(bin, pipex->cmd, pipex->envp) == -1)
			ft_perror(NAME, pipex);
}

void	create_child_process(t_pipex *pipex, char *command, int flags)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_perror(NAME, pipex);
	if (pid == 0)
	{
		pipex->cmd = ft_split(command, ' ');
		if (pipex->cmd == NULL)
			ft_perror(NAME, pipex);
		redirect_input(pipex, flags);
		redirect_output(pipex, flags);
		execute(pipex);
	}
	if (flags & SAVE_PID)
		pipex->prev_pid = pid;
}

void	run_pipes(t_pipex *pipex, char **command)
{
	if (pipe(pipex->pipe_end) == -1)
		ft_perror(NAME, pipex);
	create_child_process(pipex, command[2], FD_INFILE | FD_PIPE_OUT);
	create_child_process(pipex, command[3], FD_PIPE_IN | FD_OUTFILE | SAVE_PID);
	close(pipex->pipe_end[READ_END]);
	close(pipex->pipe_end[WRITE_END]);
}

int	wait_for_children(t_pipex *pipex)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = 1;
	while (pid > 0)
	{
		pid = wait(&status);
		if (pipex->prev_pid == pid)
			status = WEXITSTATUS(status);
	}
	free_pipex(pipex);
	return (status);
}
