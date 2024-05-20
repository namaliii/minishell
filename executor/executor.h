/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:14:12 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/20 19:22:31 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "../minishell.h"

/* paths utils */
char	**get_path(t_shell *shell);
char	*check_cmd_path(char *cmd, char **paths);

/* checks */
void	fork_check(t_shell *shell, int pid);
void	pipe_check(t_shell *shell, int *fd_pipe);
void	path_check(t_shell *shell, char *full_path, char *cmd);
void	exec_check(t_shell *shell, char *path, char **cmd, char **envp);

/* execution utils */
void	execute_child(t_shell *shell, t_node *index, int *fd_pipe);
void	execute_parent(t_node **index, int *fd_pipe);
void	execute(t_shell *shell);
void	restore_std(int *tmpin, int *tmpout);
void	create_pipe(t_shell *shell, t_node *index);

int		open_file(t_shell *shell, int type, char *file_name);
void	open_redirect_files(t_shell *shell, t_node *lst);

#endif