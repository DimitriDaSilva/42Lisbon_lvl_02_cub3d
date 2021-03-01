# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dds <dda-silv@student.42lisboa.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/11 09:33:15 by dda-silv          #+#    #+#              #
#    Updated: 2021/03/01 10:57:54 by dds              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program built
NAME				:=		cub3D

# Name directory
PATH_SRC			:=		src
PATH_BUILD			:=		build
PATH_LIBS			:=		libs
PATH_LIBFT			:=		$(PATH_LIBS)/libft
PATH_LIBMLX_MAC		:=		$(PATH_LIBS)/libmlx-mac-opengl
PATH_LIBMLX_LINUX	:=		$(PATH_LIBS)/libmlx-linux

# List of sources
SRCS				:=		$(shell find $(PATH_SRC) -name *.c)
OBJS				:=		$(SRCS:%.c=$(PATH_BUILD)/%.o)
DEPS				:=		$(OBJS:.o=.d)
INC_DIRS			:=		$(shell find $(PATH_SRC) -type d)

# Name of screnshot
BMP_SCREENSHOT		:=		screenshot.bmp

# Compiler
CC					:=		gcc

# Flags - compilation
FLAG_WARNING		:=		-O3 -Wall -Wextra -Werror
FLAG_INC			:= 		$(addprefix -I, $(INC_DIRS))
FLAG_MAKEFILE		:=		-MMD -MP
FLAG_DEBUG			:= 		-g
FLAGS_COMP			:= 		$(FLAG_WARNING) $(FLAG_INC) $(FLAG_MAKEFILE) $(FLAG_DEBUG)

# Flags - memory leak check
FLAG_MEM_LEAK		:= 		-fsanitize=address

# Flags - linking
FLAG_LIBFT			:=		-L$(PATH_LIBFT) -lft 
FLAG_LIBMLX_MAC		:=		-L$(PATH_LIBMLX_MAC) -lmlx -framework OpenGL -framework AppKit -lz
FLAG_LIBMLX_LINUX	:=		-L$(PATH_LIBMLX_LINUX) -lmlx -lX11 -lbsd -lXext
FLAGS_LINKINKG		:=		-lm $(FLAG_LIBFT) $(FLAG_LIBMLX_MAC)

# Others commands
RM					:=		rm -rf

# Color Code and template code
_YELLOW				:=		\e[38;5;184m
_GREEN				:=		\e[38;5;46m
_RESET				:=		\e[0m
_INFO				:=		[$(_YELLOW)INFO$(_RESET)]
_SUCCESS			:=		[$(_GREEN)SUCCESS$(_RESET)]

# Functions
all:						init $(NAME)
							@ echo "$(_SUCCESS) Compilation done"

debug:						FLAGS_COMP += $(FLAG_MEM_LEAK)
debug:						FLAGS_LINKINKG += $(FLAG_MEM_LEAK)
debug:						mac re

init:
							@ echo "$(_INFO) Initialize $(NAME)"
							@ make -C $(PATH_LIBFT)
							@ make -C $(PATH_LIBMLX_MAC)

$(NAME):					$(OBJS)
							$(CC) $(FLAGS_COMP) -o $@ $(OBJS) $(FLAGS_LINKINKG)


$(PATH_BUILD)/%.o:	%.c
							mkdir -p $(dir $@)
							$(CC) $(FLAGS_COMP) -c $< -o $@

bonus:						all

clean:
							@ $(RM) $(PATH_BUILD)
							@ $(RM) $(BMP_SCREENSHOT)
								@ make -C $(PATH_LIBFT) clean
							@ make -C $(PATH_LIBMLX_MAC) clean
							@ echo "$(_INFO) Deleted files and directory"

fclean:						clean
							@ $(RM) $(NAME)
							@ make -C $(PATH_LIBFT) fclean

re:							fclean all

normH:
							norminette $(shell find $(PATH_SRC) -name *.h)
							@ make -C $(PATH_LIBFT) normH

normC:
							norminette $(SRCS)
							@ make -C $(PATH_LIBFT) normC

norm:						normH normC

old_normH:
							~/.old_norminette/norminette.rb $(shell find $(PATH_SRC) -name *.h)
							@ make -C $(PATH_LIBFT) old_normH

old_normC:
							~/.old_norminette/norminette.rb $(SRCS)
							@ make -C $(PATH_LIBFT) old_normC

old_norm:					old_normH old_normC

.PHONY:						all clean fclean re

-include $(DEPS)

# Source for some pieces of this Makefile: 
# https://makefiletutorial.com/#makefile-cookbook