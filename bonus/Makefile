# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/30 10:58:29 by bwisniew          #+#    #+#              #
#    Updated: 2024/03/31 16:47:19 by bwisniew         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

C_FLAGS = -g3 -Wall -Wextra -Werror -MMD -MP

SRCS_DIR = srcs

SRCS =	main.c					\
		parsing.c				\
		ft_utils.c				\
		get_next_line.c			\
		get_next_line_utils.c	\
		print.c					\
		vector.c				\
		input.c					\
		error.c					\
		algo.c					\
		routine.c				\
		color.c					\
		mlx.c					\
		display.c				\
		hook.c

OUTDIR = obj

MINILIBX = minilibx/libmlx.a

OBJ = $(SRCS:%.c=$(OUTDIR)/%.o)

DEP = $(OBJ:%.o=%.d)

INCLUDE = includes minilibx

NAME = alum1_bonus

all: $(NAME)

$(NAME): $(MINILIBX) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MINILIBX) -Lminilibx -lmlx -Iminilibx -lXext -lX11 -lm -lz

$(OUTDIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(C_FLAGS) $(INCLUDE:%=-I %) -o $@ -c $<

$(MINILIBX): FORCE
	make -C minilibx -s

clean:
	rm -rf $(OUTDIR)
	make -C minilibx clean

fclean: clean
	rm -f $(NAME) $(MINILIBX)

re: fclean $(NAME)

FORCE:

-include $(DEP)

.PHONY: all clean fclean re FORCE