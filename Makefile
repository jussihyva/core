# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/22 22:32:30 by jkoskela          #+#    #+#              #
#    Updated: 2021/05/11 22:57:31 by jkoskela         ###   ########.fr        #
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
			@mv $(MEM)obj/*.o $(OBJ)
			@mv $(ARR)obj/*.o $(OBJ)
			@mv $(LIN)obj/*.o $(OBJ)
			@mv $(PARR)obj/*.o $(OBJ)
			@mv $(CSTR)obj/*.o $(OBJ)
			@mv $(GRAPH)obj/*.o $(OBJ)
			@mv $(MAP)obj/*.o $(OBJ)
			@mv $(MATH)obj/*.o $(OBJ)
			@mv $(PRINT)obj/*.o $(OBJ)
			@mv $(STRING)obj/*.o $(OBJ)
			@mv $(CHECKS)obj/*.o $(OBJ)
			@ar -rcs $(NAME) $(OBJ)*.o
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
