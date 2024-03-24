# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 18:14:57 by aggrigor          #+#    #+#              #
#    Updated: 2024/03/23 15:27:53 by aggrigor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME = fdf

# Compilator
CC = cc
# Compilator flags
CFLAGS = -Wall -Wextra -Werror -I minilibx_macos
LDFLAGS = -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit

# Headers
HEADERS = inc/fdf.h inc/get_next_line.h

# Source directory
SRCS_DIR = src/
# Objects directory
OBJS_DIR = objs/

# Source file names
SRCS_NAME = fdf.c \
			sidebar.c \
			sidebar_utils.c \
			hooks.c \
			ft_putstr_fd.c \
			ft_strcmp.c \
			ft_strlen.c \
			validation.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_split.c \
			ft_atoi.c \
			ft_itoa.c \
			color_utils.c \
			color_presets.c \
			button_actions.c \
			button_actions2.c \
			button_actions3.c \
			rotate.c \
			draw.c \
			draw_line.c \
			assign_utils.c \
			fdf_utils1.c \
			fdf_utils2.c 

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
