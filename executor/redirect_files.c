/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:18:17 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/21 14:52:50 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	open_redirect_files(t_shell *shell, t_node *lst)
{
	t_token	*files_cpy;
	int		fd;

	files_cpy = lst->files;
	while (files_cpy->next)
	{
		// fprintf(stderr, "looping through the files\n");
		// fprintf(stderr, "file type: %s, content: %s\n", files_cpy->content, files_cpy->next->content);
		if (files_cpy->type >= INFILE && files_cpy->type <= HEREDOC)
		{
			if (files_cpy->type == HEREDOC)
				fd = open_file(shell, files_cpy->type, files_cpy->hd_name);
			else
				fd = open_file(shell, files_cpy->type, files_cpy->next->content);
			if (files_cpy->type == INFILE || files_cpy->type == HEREDOC)
				dup2(fd, STDIN_FILENO);
			else
				dup2(fd, STDOUT_FILENO);
			close(fd);
		}
		files_cpy = files_cpy->next;
	}
}
