#Variables
NAME	= ft.out
STL		= stl.out
SRC_DIR	= src/

OBJ_DIRF	= obj_ft/
OBJ_DIRS	= obj_stl/

CPPFLAGS	= -g -Wall -Wextra -Werror
CPPFLAGS	+= -std=c++98
CC 			= c++
RM 			= rm -fr
STD_VER		= -D STD_VER

#Souces FIles
SRC_FILES	= main

#OBJS
##OBJ = $(SRC:.cpp=.o)
SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC_FILES)))
OBJ_FT			= $(addprefix $(OBJ_DIRF), $(addsuffix .o, $(SRC_FILES)))
OBJ_STL			= $(addprefix $(OBJ_DIRS), $(addsuffix .o, $(SRC_FILES)))

# make for version ft::
$(OBJ_DIRF)%.o:	$(SRC_DIR)%.cpp | $(OBJ_DIRF)
				@$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME):	$(OBJ_FT)
			@$(CC) $^ -o $@

$(OBJ_DIRF):
			@mkdir -p $(OBJ_DIRF)

# make for version std:: STL ORIGINAL
$(STL):	$(OBJ_STL)
			@$(CC) $^ -o $@

$(OBJ_DIRS)%.o:	$(SRC_DIR)%.cpp | $(OBJ_DIRS)
				@$(CC) $(STD_VER) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIRS):
			@mkdir -p $(OBJ_DIRS)

all:		$(NAME) $(STL)

clean:
		@$(RM) $(OBJ_DIRF)
		@$(RM) $(OBJ_DIRS)

fclean: clean
		$(RM) $(NAME) $(STL)

re: fclean $(NAME)

.PHONY: all clean fclean re
