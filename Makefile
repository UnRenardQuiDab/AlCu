# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/30 10:58:29 by bwisniew          #+#    #+#              #
#    Updated: 2024/03/30 12:44:50 by fsariogl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

C_FLAGS = -g3 -Wall -Wextra -Werror -MMD -MP

SRCS_DIR = srcs

SRCS =	main.c					\
		parsing.c				\
		ft_atoi.c				\
		get_next_line.c			\
		get_next_line_utils.c	\

OUTDIR = obj

OBJ = $(SRCS:%.c=$(OUTDIR)/%.o)

DEP = $(OBJ:%.o=%.d)

INCLUDE = includes

NAME = Alcu

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OUTDIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(C_FLAGS) $(INCLUDE:%=-I %) -o $@ -c $<

clean:
	rm -rf $(OUTDIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

-include $(DEP)

.PHONY: all clean fclean re