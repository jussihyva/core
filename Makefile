# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/22 22:32:30 by jkoskela          #+#    #+#              #
#    Updated: 2021/05/11 15:49:43 by jkoskela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libcore.a

MEM 		=	memory/
ARR 		=	array/
LIN 		=	linear_algebra/
PARR 		=	ptr_array/
CSTR 		=	cstring/
GRAPH 		=	graph/
MAP 		=	map/
MATH 		=	math/
PRINT		=	print/
STRING		=	string/
CHECKS		=	checks/

RM			=	rm -rf

OBJ			=	obj/


all:
			+@make -C $(MEM)
			+@make -C $(ARR)
			+@make -C $(LIN)
			+@make -C $(PARR)
			+@make -C $(CSTR)
			+@make -C $(GRAPH)
			+@make -C $(MAP)
			+@make -C $(MATH)
			+@make -C $(PRINT)
			+@make -C $(STRING)
			+@make -C $(CHECKS)
			@mkdir -p $(OBJ)
			@cp $(MEM)obj/*.o $(OBJ)
			@cp $(ARR)obj/*.o $(OBJ)
			@cp $(LIN)obj/*.o $(OBJ)
			@cp $(PARR)obj/*.o $(OBJ)
			@cp $(CSTR)obj/*.o $(OBJ)
			@cp $(GRAPH)obj/*.o $(OBJ)
			@cp $(MAP)obj/*.o $(OBJ)
			@cp $(PRINT)obj/*.o $(OBJ)
			@cp $(STRING)obj/*.o $(OBJ)
			@cp $(CHECKS)obj/*.o $(OBJ)
			ar -rcs $(NAME) $(OBJ)*.o
			@echo "\\n\033[32;1mCORE ACTIVATED \033[0m \\n"

clean:
			@make clean -C $(MEM)
			@make clean -C $(ARR)
			@make clean -C $(LIN)
			@make clean -C $(PARR)
			@make clean -C $(CSTR)
			@make clean -C $(GRAPH)
			@make clean -C $(MAP)
			@make clean -C $(MATH)
			@make clean -C $(PRINT)
			@make clean -C $(STRING)
			@make clean -C $(CHECKS)
			@echo "\\n\033[32;1mCORE DEACTIVATED \033[0m \\n"

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(OBJ)
			@make fclean -C $(MEM)
			@make fclean -C $(ARR)
			@make fclean -C $(LIN)
			@make fclean -C $(PARR)
			@make fclean -C $(CSTR)
			@make fclean -C $(GRAPH)
			@make fclean -C $(MAP)
			@make fclean -C $(MATH)
			@make fclean -C $(PRINT)
			@make fclean -C $(STRING)
			@make fclean -C $(CHECKS)

re:			fclean all

.PHONY: 	all fclean clean re
