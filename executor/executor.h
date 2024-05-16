/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:14:12 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/16 14:21:20 by anamieta         ###   ########.fr       */
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

/* execution utils */
void	execute(t_shell *shell);

#endif