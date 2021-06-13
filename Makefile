.PHONY:		all re clean fclean norme debug test

NAME = pipex
SRCDIR = ./src/
LIBFTDIR = ./libft/
LIBFT = $(LIBFTDIR)libft.a
INCLD_LIBFT = -I ./libft/includes/
INCLD = -I ./includes
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INCLD) $(INCLD_LIBFT) -O3 -MD

FILES_PIPEX = main.c pipex.c execute.c find_path_cmd.c

SRC_PIPEX = $(addprefix $(SRCDIR), $(FILES_PIPEX))
OBJS = $(SRC_PIPEX:.c=.o)
D_FILES = $(SRC_PIPEX:.c=.d)

all: $(NAME)

debug: CFLAGS += -fsanitize=address -g
debug: all

$(NAME): $(OBJS) | tools
		$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME)
include $(wildcard $(D_FILES))

tools:
		make -C $(LIBFTDIR)
norme: fclean
		norminette $(SRC_PIPEX) ./includes/*
		make -C $(LIBFTDIR) norme
test: all
		cp ./pipex ./test/pipex
		./test/test.sh
clean:
		rm -f $(OBJS) $(D_FILES)
		make -C $(LIBFTDIR) clean
fclean: clean
		rm -f ${NAME}
		make -C $(LIBFTDIR) fclean

re: fclean all
