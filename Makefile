# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 13:27:33 by elerazo-          #+#    #+#              #
#    Updated: 2026/01/27 13:58:09 by elerazo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		=	cub3d
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g -I inc/ 
#CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g -I inc/ 
MINIFLAGS	=	-lXext -lX11 -lm -lz 
OBJDIR		=	build
SRCSDIR		=	src
SRCS		=	main.c utils.c parse_cub.c detector.c save.c keys.c \
				raycast.c keys_handler.c calculate.c error_handler.c \
				init_img.c check.c init.c 

MLX_PATH	=	./libs/minilibx
LIBFT_PATH	=	./libs/libft/
#PRINTF_PATH =	./libs/printf/
MLX			=	$(MLX_PATH)/libmlx.a $(MLX_PATH)/libmlx_Linux.a
LIBFT		=	$(LIBFT_PATH)/libft.a
#PRINTF		=	$(PRINTF_PATH)/libftprintf.a

OBJS		=	$(addprefix $(OBJDIR)/, ${SRCS:.c=.o})

PURPLE		=	\033[0;33m
BLUE		=	\033[0;33m
GREEN		=	\033[0;32m
RED			=	\033[0;31m
RESET		=	\033[m

all: banner $(NAME)

banner:
	@printf "%b" "$(PURPLE)\n"
	@echo "# ========================== #"
	@echo "#        CUB3D               #"
	@echo "# by: elerazo and israetor   #"
	@echo "# ========================== #"
	@printf "%b" "\n$(RESET)"

$(OBJS): $(OBJDIR)/%.o : $(SRCSDIR)/%.c Makefile inc/cub3d.h | $(OBJDIR)
	@printf "%-42b" "$(BLUE)compiling... $(PURPLE)$(@F)$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@-mkdir $(OBJDIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX) #$(PRINTF) $(MLX)
	@printf "%-42b" "$(BLUE)linking... $(PURPLE)$(@F)$(RESET)\n"
	@$(CC) $(CFLAGS) $^ $(MINIFLAGS) -o $@

$(MLX):
	@make -C $(MLX_PATH) > /dev/null 2>&1

$(LIBFT):
	@make -C $(LIBFT_PATH)  > /dev/null 2>&1

#$(PRINTF):
#	@make -C $(PRINTF_PATH) > /dev/null 2>&1

fclean: banner clean
	@printf "%b" "$(BLUE)$(@)ing...$(RESET)\n"
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH) > /dev/null 2>&1
#	@make fclean -C $(PRINTF_PATH) > /dev/null 2>&1

clean: banner
	@printf "%b" "$(BLUE)$(@)ing...$(RESET)\n"
	@rm -rf $(OBJDIR)
	@make clean -C $(LIBFT_PATH) > /dev/null 2>&1
#	@make clean -C $(PRINTF_PATH) > /dev/null 2>&1

re:    fclean all

.PHONY: all banner clean fclean re $(MLX) $(LIBFT) #$(PRINTF)
