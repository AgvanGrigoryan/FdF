# Project name
NAME = fdf

# Compilator
CC = cc
# Compilator flags
CFLAGS = -Wall -Wextra -Werror -I minilibx_macos #-g3 -fsanitize=address
LDFLAGS = -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit

# Headers
HEADERS = includes/fdf.h

# Source directory
SRCS_DIR = utilities/
# Objects directory
OBJS_DIR = objects/

# Source file names
SRCS_NAME = fdf.c \
			ft_putstr_fd.c \
			ft_strcmp.c \
			ft_strlen.c \
			validation.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_split.c \
			ft_atoi.c \
			fdf_utils1.c

# Objects file names
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))
OBJS_NAME = $(SRCS_NAME:.c=.o)

# Compilation process
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

# Remaking
re: clean all

# PHONY files
.PHONY: all clean fclean re
