# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/22 22:32:30 by jkoskela          #+#    #+#              #
#    Updated: 2021/04/24 23:14:46 by jkoskela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libcore.a

MEM 		=	mem/
ARR 		=	arr/
LIN 		=	lin/
PARR 		=	parr/
CSTR 		=	cstr/

MEM_A 		=	mem/libmem.a
ARR_A 		=	arr/libarr.a
LIN_A 		=	lin/liblin.a
PARR_A 		=	parr/libparr.a
CSTR_A 		=	cstr/libcstr.a

RM			=	rm -rf

OBJ			=	obj/


all:
			+@make -C $(MEM)
			+@make -C $(ARR)
			+@make -C $(LIN)
			+@make -C $(PARR)
			+@make -C $(CSTR)
			@mkdir -p $(OBJ)
			@cp $(MEM)obj/*.o $(OBJ)
			@cp $(ARR)obj/*.o $(OBJ)
			@cp $(LIN)obj/*.o $(OBJ)
			@cp $(PARR)obj/*.o $(OBJ)
			@cp $(CSTR)obj/*.o $(OBJ)
			ar -rcs $(NAME) $(OBJ)*.o
			@echo "\\n\033[32;1mCORE ACTIVATED \033[0m \\n"

clean:
			@make clean -C $(MEM)
			@make clean -C $(ARR)
			@make clean -C $(LIN)
			@make clean -C $(PARR)
			@make clean -C $(CSTR)
			@echo "\\n\033[32;1mCORE DEACTIVATED \033[0m \\n"

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(OBJ)
			@make fclean -C $(MEM)
			@make fclean -C $(ARR)
			@make fclean -C $(LIN)
			@make fclean -C $(PARR)
			@make fclean -C $(CSTR)

re:			fclean all

.PHONY: 	all fclean clean re
