/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:32:10 by anamieta          #+#    #+#             */
/*   Updated: 2024/05/21 13:21:36 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	heredoc(t_shell *shell)
{
	t_node	*s_cmd;
	t_token	*files;
	char	*line;
	int		count;
	int		fd;

	count = 0;
	s_cmd = shell->s_cmd;
	while (s_cmd)
	{
		files = s_cmd->files;
		while (files)
		{
			if (files->type == HEREDOC)
			{
				assign_name(&files, &count);
				fd = open_file(shell, files->type, files->hd_name);
				while (1)
				{
					line = readline("> ");
					if (ft_strlen(line) == ft_strlen(files->next->content))
					{
						if (ft_strncmp(line, files->next->content, ft_strlen(line)) == 0)
						{
							break;
						}
					}
					else
					{
						write(fd, line, ft_strlen(line));
						write(fd, "\n", 1);
					}
				}
				close(fd);
			}
			files = files->next;
		}
		s_cmd = s_cmd->next;
	}
}

void	assign_name(t_token **file, int *count)
{
	t_token	*index;
	int		i;

	index = *file;
	i = 0;
	while (i < 10)
	{
		index->hd_name[i] = '\0';
		i++;
	}
	index->hd_name[0] = 'f';
	index->hd_name[1] = 'i';
	index->hd_name[2] = 'l';
	index->hd_name[3] = 'e';
	index->hd_name[4] = *count + '0';
	*count = *count + 1;
}

void	print_hd_names(t_shell *shell)
{
	t_node	*s_cmd;
	t_token	*files;

	s_cmd = shell->s_cmd;
	while (s_cmd)
	{
		files = s_cmd->files;
		while (files)
		{
			if (files->type == HEREDOC)
				printf("file : %u name : %s \n", files->type, files->hd_name);
			files = files->next;
		}
		s_cmd = s_cmd->next;
	}
}
