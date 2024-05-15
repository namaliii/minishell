/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:14:12 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/15 14:41:06 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum s_token_type
{
	WORD,
	INFILE,
	OUTFILE,
	APPEND,
	HEREDOC,
	PIPE
}			t_token_type;

typedef struct s_token
{
	t_token_type		type;
	char				*content;
	struct s_token		*next;
	struct s_token		*prev;
}						t_token;

typedef struct s_node
{
	char			**cmd;
	t_token			*files;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

// typedef struct s_heredoc
// {
// 	char				*limiter;
// 	bool				expand;
// 	struct s_heredoc	*next;
// }				t_heredoc;

typedef struct s_shell
{
	t_node			*lst;
	// t_heredoc		*heredoc;
	// char			*last_hd_name;
	// int				fd_last_hd;
	char			**my_env;
	int				exit_code;
}	t_shell;

#endif