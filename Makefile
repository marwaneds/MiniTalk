# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 14:50:43 by mel-faqu          #+#    #+#              #
#    Updated: 2023/02/13 16:03:03 by mel-faqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/bash

NAME		= client
NAMESV		= server
NAMEBC		= client_bonus
NAMEBS		= server_bonus
LIBFT		= libft
INC		= inc
HEADER		= -I inc
SRC_DIR		= src/
OBJ_DIR		= obj/
CC		= gcc
FLAGS		= -Wall -Werror -Wextra
FSANITIZE	= -fsanitize=address -g3
RM		= rm -f
ECHO		= echo -e

SRCCL_FILES	=	client
SRCSV_FILES	=	server
SRCBC_FILES	=	client_bonus
SRCBS_FILES	=	server_bonus

SRCCL 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCCL_FILES)))
OBJCL 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCCL_FILES)))

SRCSV 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCSV_FILES)))
OBJSV 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCSV_FILES)))

SRCBC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCBC_FILES)))
OBJBC 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCBC_FILES)))

SRCBS 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCBS_FILES)))
OBJBS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCBS_FILES)))


OBJF		=	.cache_exists

start:
			@make -C $(LIBFT)
			@cp $(LIBFT)/libft.a .
			@$(ECHO) -n "[Dependencies]:\t"
			@$(ECHO) -n "[================================================"
			@make all

all:		$(NAME) $(NAMESV)

$(NAME):	$(OBJCL) $(OBJF)
			@$(CC) $(FLAGS) $(OBJCL) $(HEADER) libft.a -o $(NAME)

$(NAMESV):	$(OBJSV) $(OBJF)
			@$(ECHO) -n "]"
			@$(ECHO) -n " => 100%\n"
			@$(ECHO) -n "[minitalk]:\t"
			@$(CC) $(FLAGS) $(OBJSV) $(HEADER) libft.a -o $(NAMESV)
			@$(ECHO) " => Success!"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(OBJF)
			@$(ECHO) -n "="
			@$(CC) $(FLAGS) $(HEADER) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@touch $(OBJF)

$(NAMEBC):	$(OBJBC) $(OBJF)
			@$(CC) $(FLAGS) $(OBJBC) $(HEADER) libft.a -o $(NAMEBC)

$(NAMEBS):	$(OBJBS) $(OBJF)
			@$(ECHO) -n "]"
			@$(ECHO) -n "=> 100%\n"
			@$(ECHO) -n "$(YELLOW)[minitalk_bonus]:\t$(DEF_COLOR)"
			@$(CC) $(FLAGS) $(OBJBS) $(HEADER) libft.a -o $(NAMEBS)
			@$(ECHO) "$(GREEN) => Success!$(DEF_COLOR)"

clean:
			@$(RM) -r $(OBJ_DIR)
			@$(RM) $(OBJF)
			@make clean -C $(LIBFT)
			@$(ECHO) -n "[minitalk]:\tobject files  => Cleaned!\n"

fclean:		clean
			@$(RM) $(NAME) $(NAMESV) $(NAMEBC) $(NAMEBS)
			@$(RM) $(LIBFT)/libft.a
			@$(RM) libft.a
			@find . -name ".DS_Store" -delete
			@$(ECHO) -n "[LIBFT]:\texec. files=  => Cleaned!\n"
			@$(ECHO) -n "[minitalk]:\texec. files=  => Cleaned!\n"


re:			fclean all
			@$(ECHO) -n "=Cleaned and rebuilt everything for [minitalk]!=\n"

norm:
			@clear
			@norminette $(SRC) $(INC) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:		start all clean fclean re norm

