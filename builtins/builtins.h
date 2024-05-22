/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:14:12 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/22 17:54:45 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../minishell.h"

void					env(t_env	*env);
int						echo(char **cmd);
void					pwd(void);
void					unset(t_env **env, char *str);

// builtins helper***********

void					clean_env(t_shell *shell);
t_env					*ft_get_env(char **env);
void					env_delete(t_env **env, char *var);
void					env_free(t_env **node);

#endif