/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:14:12 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/19 12:25:27 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "../minishell.h"

char	*get_env_value(t_shell *shell, char *key);
char	*expand(char *str, t_shell *shell);
void	handle_db_quotes(int *i, char *str, t_char **new, t_shell *shell);
void	handle_dollar(int *i, char *str, t_char **new, t_shell *shell);
void	init_tmp(char *tmp, int start, int index, char *str);
void	extract_tmp(char *tmp, t_char **new);
int		stop_crawling(int c);
int		get_t_char_length(t_char **new);
char	*charlst_to_str(t_char **new);
void	handle_exit_code(int *i, t_char **new, t_shell *shell);
void	handle_double_dollar(int *i, t_char **new);
void	handle_simple_char(int *i, char *str, t_char **new);
void	expand_all(t_shell *shell);
void	delete_expanded_node(t_token **node);

#endif