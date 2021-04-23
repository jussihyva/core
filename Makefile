# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/22 22:32:30 by jkoskela          #+#    #+#              #
#    Updated: 2021/04/21 14:29:31 by julius           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libcore.a

MEM 		=	mem/
ARR 		=	arr/

MEM_A 		=	mem/libmem.a
ARR_A 		=	arr/libarr.a
RM			=	rm -rf

OBJ			=	obj/


all:
			+@make -C $(MEM)
			+@make -C $(ARR)
			@mkdir -p $(OBJ)
			@cp $(MEM)obj/*.o $(OBJ)
			@cp $(ARR)obj/*.o $(OBJ)
			ar -rcs $(NAME) $(OBJ)*.o
			@echo "\\n\033[32;1mCORE ACTIVATED \033[0m \\n"

clean:
			@make clean -C $(MEM)
			@make clean -C $(ARR)
			@echo "\\n\033[32;1mCORE DEACTIVATED \033[0m \\n"

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(OBJ)
			@make fclean -C $(MEM)
			@make fclean -C $(ARR)

re:			fclean all

.PHONY: 	all fclean clean re
