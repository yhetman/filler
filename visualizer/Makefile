# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/03 19:38:02 by azavrazh          #+#    #+#              #
#    Updated: 2019/04/05 17:26:57 by yhetman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re mclean mfclean mre

NAME := yhetman.vis

SRC_PATH :=	
INC_PATH :=	
LIB_PATH :=	../libft/
OBJ_PATH :=	obj/

CC :=		clang
IFLAGS :=	-I . -I $(LIB_PATH)

LIB :=		$(LIB_PATH)libft.a
HFILES :=	visualizer
FILES :=	visualizer yhetman_vis

HDRS :=		$(addprefix $(INC_PATH), $(addsuffix .h, $(HFILES)))
SRCS :=		$(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS :=		$(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))


all: $(NAME)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJS)
	$(CC) $(IFLAGS) $(OBJS) $(LIB) -lncurses -o $(NAME)

$(LIB):
	make -C $(LIB_PATH)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)
$(OBJ_PATH)%.o: %.c $(HDRS)

	$(CC) $(IFLAGS) -c $< -o $@

clean: mclean
	make clean -C $(LIB_PATH)
fclean: mfclean
	make fclean -C $(LIB_PATH)
	rm -rf $(NAME)
re: fclean all

mclean:
	rm -rf $(OBJ_PATH)
mfclean:
	rm -rf $(NAME)
	rm -rf $(OBJ_PATH)
mre: mfclean all
