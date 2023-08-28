# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalic <asalic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 15:24:47 by asalic            #+#    #+#              #
#    Updated: 2023/06/23 13:01:17 by asalic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = so_long
PATHLIBX = minilibx-linux/libmlx.a
PATHPRINTF = libftprintf/libftprintf.a
INCLUDE = minilibx-linux/mlx.h so_long.h libftprintf/libftprintf.h
LIBS = -lGL -lmlx -lXext -lX11 -lm

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -O0

SRC = so_long.c img_pop.c utils.c utils_bis.c help.c is_moving.c \
	parsing/main_parse.c parsing/choose_path.c parsing/utils_parse.c \
	parsing/main_coreparse.c error_cases/check_map.c \
	error_cases/file_error.c error_cases/check_thing.c error_cases/bord2.c \

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

all : $(PATHLIBX) $(PATHPRINTF) $(EXEC) $(INCLUDE)

$(OBJ_DIR)/%.o :%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/parsing
	@mkdir -p $(OBJ_DIR)/error_cases
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC) : $(OBJ)
	@$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) -Lminilibx-linux -Llibftprintf -lftprintf $(LIBS)
	@echo "---Compilation done---\n"

$(PATHPRINTF) :
	@make -s -C libftprintf
	
$(PATHLIBX) :
	@make -s -C minilibx-linux

clean :
	@echo "---Clean done---\n"
	@rm -rf $(OBJ_DIR) $(OBJ)
	@make -s clean -C minilibx-linux
	@make -s clean -C libftprintf

fclean : clean
	@echo "---Fclean done---\n"
	@rm -rf $(EXEC)
	@make -s fclean -C libftprintf

test:	$(EXEC)
	./$(EXEC) MAPS/ERROR_MAP/maptest.ber

vtest:	$(EXEC)
	valgrind --leak-check=full ./$(EXEC) MAPS/ERROR_MAP/maptest.ber

re : fclean
	@make -s all

.PHONY : all clean fclean re test vtest
