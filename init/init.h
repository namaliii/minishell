/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:14:12 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/22 18:51:40 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "../minishell.h"

void	shell_init(t_shell *shell, char **env);
void	shell_setup(t_shell *shell, char *line);
int		include_quotes(char *str);
void	set_hd_expanded(t_token **tokens);
char	**init_builtins(void);
#endif