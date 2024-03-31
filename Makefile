# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/30 10:58:29 by bwisniew          #+#    #+#              #
#    Updated: 2024/03/31 20:15:31 by bwisniew         ###   ########.fr        #
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
		routine.c

OUTDIR = obj

OBJ = $(SRCS:%.c=$(OUTDIR)/%.o)

DEP = $(OBJ:%.o=%.d)

INCLUDE = includes

NAME = alum1

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OUTDIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(C_FLAGS) $(INCLUDE:%=-I %) -o $@ -c $<

bonus:
	make -C bonus

clean:
	rm -rf $(OUTDIR)
	make -C bonus clean

fclean: clean
	rm -f $(NAME)
	make -C bonus fclean

re: fclean $(NAME)

-include $(DEP)

.PHONY: all clean fclean re bonus