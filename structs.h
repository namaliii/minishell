/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:14:12 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/21 12:15:59 by anamieta         ###   ########.fr       */
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
	char				hd_name[10];
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

typedef struct s_env
{
	char			**content;
	struct s_env	*next;
	struct s_env	*prev;
}				t_env;

typedef struct s_char
{
	char			c;
	struct s_char	*next;
}					t_char;

// typedef struct s_heredoc
// {
// 	char				*limiter;
// 	bool				expand;
// 	struct s_heredoc	*next;
// }				t_heredoc;

	// t_heredoc		*heredoc;
	// char			*last_hd_name;
	// int				fd_last_hd;
	// int				exit_code;

typedef struct s_shell
{
	t_token			*tokens;
	t_node			*s_cmd;
	t_env			*env;
	char			**path;
	int				exit_code;
	int				fd_pipe[2];
}	t_shell;

#endif