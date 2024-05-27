/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:14:12 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/27 17:50:28 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

# include "../minishell.h"

/** token list manipulation */

t_token				*token_last(t_token *lst);
t_token				*token_new(char *content, t_token_type type);
void				token_add_back(t_token **lst, t_token *new);

/** token list printing */
void				print_tokens(t_token *lst);
void				print_nodes(t_node *s_cmd);
void				print_char(char **str);
void				print_c(t_char *lst);

/** node list manipulation */

t_node				*node_last(t_node *lst);
void				node_add_back(t_node **lst, t_node *new);
t_node				*node_new(char **cmd, t_token *files);

/** env list manipulation */

t_env				*env_last(t_env *lst);
void				env_add_back(t_env **lst, t_env *new);
t_env				*env_new(char **content);

/** char list manipulation */

t_char				*char_last(t_char *lst);
void				char_add_back(t_char **lst, t_char *new);
t_char				*char_new(char content);
t_char				*str_to_charlst(char *str);

#endif