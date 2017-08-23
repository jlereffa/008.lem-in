# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/26 13:43:21 by jlereffa          #+#    #+#              #
#    Updated: 2017/08/23 13:37:41 by jlereffa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##PROJECT
NAME = lem-in
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2

##DIRECTORIES
SRC_PATH = srcs/
OBJ_PATH = objs/
INC_PATH = includes/
INC_LIBFT_PATH = libft/includes/
LIBFT_PATH = libft/

##FILES
SRC_NAME =	main.c handle_error.c rewind_t_lem_in_file.c set_t_lem_in_file.c\
			stock_content.c init_t_lem_in_var.c\
			check_if_str_identical.c check_ants_nb.c check_room.c\
			check_commands_and_comments.c check_if_room_or_path.c check_path.c\
			estimate_if_doable.c parse_content_in_depth.c\
			format_content_into_lst.c set_t_lem_in_room.c set_t_lem_in_path.c\
			add_path_to_room.c parse_content_light.c\
			rewind_t_lem_in_room.c rewind_t_lem_in_path.c apply_algorithm.c\
			set_t_lem_in_ant.c init_t_lem_in_ant.c\
			rewind_t_lem_in_ant.c find_and_print_solution.c free_all_struct.c\
			del_and_set_to_null_t_lem_in_file.c\
			del_and_set_to_null_t_lem_in_ant.c\
			del_and_set_to_null_t_lem_in_room.c\
			del_and_set_to_null_t_lem_in_path.c print_error_msg.c

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = -lft
HEADER_PROJECT = lem_in.h
HEADER_LIBFT = libft.h

##VARIABLES
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIBFT = $(addprefix -L,$(LIBFT_PATH))
INC = $(addprefix -I,$(INC_PATH))
INC_LIBFT = $(addprefix -I,$(INC_LIBFT_PATH))
HEADER = $(addprefix $(INC_PATH),$(HEADER_PROJECT))
HEADER_LIB = $(addprefix $(INC_LIBFT_PATH),$(HEADER_LIBFT))

##RULES
all: $(NAME)

$(NAME): libft $(OBJ)
	@$(CC) $(LIBFT) $(LIB_NAME) -o $@ $(OBJ)
	@echo "\n\033[1;34m [$(NAME)] %.o\t\t\033[1;32m[Created]\033[0m"
	@echo "\033[1;34m [$(NAME)] $(NAME)\t\033[1;32m[Created]\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER) $(HEADER_LIB)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) $(INC_LIBFT) -o $@ -c $<
	@echo "\033[32m█\033[0m\c"

clean:
	@rm -rf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@make clean -C $(LIBFT_PATH)
	@echo "\033[1;34m [$(NAME)] %.o\t\033[1;31m[Removed]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[1;34m [$(NAME)] $(NAME)\t\t\033[1;31m[Removed]\033[0m"

re: fclean all

norm:
	@clear
	@echo "\x1b[35m\n.==================[ \x1b[0m\c"
	@echo "\x1b[35;1mNormi-Check\x1b[0m\c"
	@echo " \x1b[35m]==================.\x1b[37;1m"
	@norminette $(INC_PATH) $(SRC_PATH) \
	| tr "\n" "@" \
	| sed -e "s/Norme: /$$/g" \
	| tr "$$" "\n" \
	| grep -e Error -e Warning \
	| tr "@" "\n" \
	| sed "N;$$!P;$$!D;$$d"
	@echo "\x1b[0m\x1b[35m\c"
	@echo ".___________________________________________________.\n\x1b[0m"

libft:
	@make -C $(LIBFT_PATH)

.PHONY: libft all clean fclean re norm
