NAME	:= minishell

CC		:=	cc
CFLAGS	:=	-Wextra -Wall -Werror

SRCS := main.c \
	builtins/cd.c \
	builtins/echo.c \
	builtins/env.c \
	builtins/env_utils.c \
	builtins/execute_builtins.c \
	builtins/exit.c \
	builtins/export.c \
	builtins/export_utils.c \
	builtins/pwd.c \
	builtins/unset.c \
	checks/quotes_checks.c \
	executor/checks.c \
	executor/exec_env.c \
	executor/execute.c \
	executor/execute_utils.c \
	executor/heredoc.c \
	executor/open.c \
	executor/path.c \
	executor/redirect_files.c \
	expander/crawler.c \
	expander/expand.c \
	expander/expand_handler.c \
	expander/expand_utils.c \
	init/shell_init.c \
	lexer/helper_lexer.c \
	lexer/lexer.c \
	libft/ft_atoi.c \
	libft/ft_calloc.c \
	libft/ft_isalnum.c \
	libft/ft_isalpha.c \
	libft/ft_isdigit.c \
	libft/ft_isspace.c \
	libft/ft_itoa.c \
	libft/ft_putstr_fd.c \
	libft/ft_split.c \
	libft/ft_strdup.c \
	libft/ft_strdup2.c \
	libft/ft_strjoin.c \
	libft/ft_strlcpy.c \
	libft/ft_strncmp.c \
	lists/char_list.c \
	lists/env_lists.c \
	lists/node_lists.c \
	lists/print_lists.c \
	lists/token_lists.c \
	parser/clean_nodes.c \
	parser/parser.c \
	parser/parser_get.c \
	parser/t_cmd.c \
	signals/setup_signals.c \
	signals/signals.c

OBJS	:=	${SRCS:.c=.o}

all: $(NAME)


$(NAME): $(OBJS)
	@echo "Compiling shell ..."
	@$(CC) $(OBJS) -o $(NAME) -lreadline

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJS)

fclean: clean
	@echo "Cleaning minishell"
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re