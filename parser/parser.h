/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:14:12 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/30 16:54:47 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../minishell.h"

void	parser(t_token **tokens, t_node **s_cmd);
void	t_cmd(t_node **s_cmd, t_token **index, t_token **files, t_token **cmd);
char	**list_to_char(t_token **cmd);
int		get_list_length(t_token *cmd);
void	get_cmd(t_token **index, t_token **cmd);
void	get_file(t_token **index, t_token **files);
int		is_pipe(t_token *index);
void	clean_nodes(t_node **node);
void	clean_array(char **str);
void	clean_files(t_token **files);
void	clean_shell(t_shell *shell);

#endif