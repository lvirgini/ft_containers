# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 17:38:13 by lvirgini          #+#    #+#              #
#    Updated: 2022/08/03 08:37:59 by lvirgini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------- #
#	 VARIABLES		#
# ----------------- #

NAME 	= ft_containers
NAMESTD = std_containers


# Includes
# ----------------- #
INC_DIR	=	includes \
			includes/others \
			includes/iterator \
			includes/red_black_tree \

INCLUDE	=	$(INC_MAP) $(INC_VECTOR) $(INC_STACK) $(INC_UTILS)\
				ft_stl.hpp \
				printer.tpp \

INC_STACK	=	stack.hpp \

INC_VECTOR	=	vector.hpp \

INC_MAP 	=	map.hpp	\

INC_UTILS 	=	usefull.hpp \
				type_traits.hpp \
				iterators_traits.hpp \
				normal_iterator.hpp \
				reverse_iterator.hpp \
				RedBlacktree.hpp \
				TreeNode.hpp \
				pair.hpp \
				
			
HEADERS 	=	$(foreach dir, $(INC_DIR), $(wildcard $(dir)/*.hpp) )


# Sources
# ----------------- #

SRC_DIR		=	srcs srcs/vector srcs/stack srcs/map srcs/set

SRC			= 	$(SRC_VECTOR) $(SRC_STACK) $(SRC_MAP) $(SRC_SET) main.cpp \

SRC_VECTOR	=	vector_test_iterator.cpp \
				vector_test_empty.cpp \
				vector_test_vector.cpp \
				vector_test_insert.cpp \
				vector_test_push_pop.cpp \
				vector_test_operator.cpp \
				vector_test_assign.cpp \
				vector_test_erase.cpp \

SRC_STACK	=	stack_test.cpp \

SRC_MAP 	=	test_pair.cpp \
				test_rbtree.cpp \
				map_test_constructor.cpp \
				map_test_capacity.cpp \
				map_test_insert.cpp \
				map_test_erase.cpp \
				map_test_iterator.cpp \
				map_test_others_functions.cpp

SRC_SET		=	set_test_bound.cpp \
				set_test_constructor.cpp \
				set_test_erase.cpp \
				set_test_find.cpp \
				set_test_insert.cpp \
				set_test_iterator.cpp \
				set_test_size.cpp \
				set_test_others_functions.cpp \

# Obj
# ----------------- #	
OBJ_DIR		=	obj/
OBJ_DIRSTD	=	objstd/

OBJ 	=	$(addprefix $(OBJ_DIR),$(SRC:%.cpp=%.o))
OBJ_STD =	$(addprefix $(OBJ_DIRSTD),$(SRC:%.cpp=%.o))

# ----------------- #
#	 COMPILATION	#
# ----------------- #

CC 		=	clang++

CFLAG 	= 	-Wall -Wextra -Werror -std=c++98
STDFLAG = -D M_NAMESPACE=std
IFLAG 	=	$(foreach dir, $(INC_DIR), -I $(dir)/ )


vpath %.cpp $(foreach dir, $(SRC_DIR)/, $(dir):)
vpath %.hpp $(foreach dir, $(INC_DIR)/, $(dir):)

# ----------------- #
#	  FONCTIONS		#
# ----------------- #

all:		$(NAME) $(NAMESTD)

$(OBJ_DIR)%.o: %.cpp $(HEADERS)
			@mkdir -p $(OBJ_DIR)
			@echo "\033[32mCompilation of ... $(foreach file, $< , $(notdir $<))\033[0m"
			@$(CC) $(CFLAG) $(IFLAG) -o $@ -c $< 

$(OBJ_DIRSTD)%.o: %.cpp $(HEADERS)
			@mkdir -p $(OBJ_DIRSTD)
			@echo "\033[32mCompilation of ... $(foreach file, $< , $(notdir $<))\033[0m"
			@$(CC) $(CFLAG) $(STDFLAG) $(IFLAG) -o $@ -c $< 

$(NAME):	$(OBJ)
			@$(CC) $(CFLAG) $(IFLAG) $(OBJ) -o $@ 
			@echo "\033[32mC\n*     Compilation $(NAME)     *\t   \033[32;1m--> Complete\033[0m"

$(NAMESTD):	$(OBJ_STD)
			@$(CC) $(CFLAG) $(STDFLAG) $(IFLAG) $(OBJ_STD) -o $@ 
			@echo "\033[32mC\n*     Compilation $(NAMESTD)     *\t   \033[32;1m--> Complete\033[0m"

bonus:		all

# ----------------- #
# 		CLEAN		#
# ----------------- #

clean:
			rm -rf $(OBJ_DIR) $(OBJ_DIRSTD)

fclean: clean
			rm -f $(NAME) $(NAMESTD) *.log

re: 	fclean all

.PHONY: all clean flcean re
