NAME = push_swap

SRCS =	srcs/main.c \
		srcs/simplify_int.c \
		srcs/tri.c \
		srcs/tri2_3.c \
		srcs/tri4.c \
		srcs/tri5.c \
		srcs/utils.c \
		srcs/utils2.c \
		srcs/algo.c

FLAGS = -Wall -Wextra -Werror

HEADER_FILE = ./include

HEADERS =	$(HEADER_FILE)/push_swap.h \
			libft/libft.h

LIB_NAME = libft/libft.a

OBJS = ${SRCS:.c=.o}

.PHONY: all
.PHONY: clean
.PHONY: fclean
.PHONY: re

$(NAME): $(OBJS) $(LIB_NAME)
	clang $(OBJS) $(LIB_NAME) -o $(NAME)

$(OBJS): %.o: %.c $(HEADERS)
	clang $(FLAGS) -I$(HEADER_FILE) -c $< -o $@

$(LIB_NAME):
	$(MAKE) -C libft


all: $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)

re: fclean all