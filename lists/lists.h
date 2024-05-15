/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:14:12 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/15 15:11:12 by mfaoussi         ###   ########.fr       */
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

/** node list manipulation */

t_node				*node_last(t_node *lst);
void				node_add_back(t_node **lst, t_node *new);
t_node				*node_new(char **cmd, t_token *files);

/** env list manipulation */

t_env				*env_last(t_env *lst);
void				env_add_back(t_env **lst, t_env *new);
t_env				*env_new(char **content);

#endif