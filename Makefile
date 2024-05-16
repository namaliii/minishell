NAME	:= exec

CC		:=	cc
CFLAGS	:=	-Wextra -Wall -Werror

SRCS	:=	$(wildcard *.c) $(wildcard */*.c)

OBJS	:=	${SRCS:.c=.o}

all: $(NAME)


$(NAME): $(OBJS)
	@echo "Compiling shell ..."
	@$(CC) $(OBJS) -o $(NAME) -lreadline

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJS)

fclean: clean
	@echo "Cleaning exec"
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re