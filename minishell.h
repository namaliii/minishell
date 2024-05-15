/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:14:12 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/15 11:56:33 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>

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

int						check_quotes(char *input);
int						check_single_quotes(char *input);
int						check_double_quotes(char *input);
void					print_tokens(t_token *lst);

#endif