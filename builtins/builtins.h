/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:14:12 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/27 12:46:02 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../minishell.h"

void					env(t_env	*env);
int						echo(char **cmd);
void					pwd(void);
void					unset(t_env **env, t_node *index);
void					export(t_shell *shell, t_node *index);
void					cd(t_shell	*shell, t_node *index);

// builtins helper***********

void					clean_env(t_shell *shell);
t_env					*ft_get_env(char **env);
void					env_delete(t_env **env, char *var);
void					env_free(t_env **node);
int						check_export(char *str, int length);
void					add_to_env(char *str, t_shell *shell);
void					print_export_error(char *str);
int						get_equal_position(char *str);
int						check_equal(char *str);
t_env					*point_to_env(char *key, t_shell *shell);
void					update_env(char *str, t_shell *shell);

int						is_builtin(t_shell *shell, char *cmd);
void					execute_builtins(t_node *index, t_shell *shell);
char					*get_pwd(void);

#endif