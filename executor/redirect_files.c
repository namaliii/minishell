/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:18:17 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/20 19:48:29 by anamieta         ###   ########.fr       */
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
		if (files_cpy->type >= INFILE && files_cpy->type <= APPEND)
		{
			fd = open_file(shell, files_cpy->type, files_cpy->next->content);
			if (files_cpy->type == INFILE)
				dup2(fd, STDIN_FILENO);
			else
				dup2(fd, STDOUT_FILENO);
			close(fd);
		}
		files_cpy = files_cpy->next;
	}
}
