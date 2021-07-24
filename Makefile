NAME = cub3D

#SRC_DIR = include/src/
OBJ_DIR = obj/
LIBFT_DIR = include/libft/
MLX_DIR = include/minilibx_mms/


#INCLUDES = -I ./includes -I ./libft

CC = gcc
FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit libmlx.dylib
LIBFT = libft.a

SRCS = main.c \
	utils/start_cub3d.c \
	parser/parser.c \
	parser/parser_map.c \
	parser/check_space_wall.c \
	checkers_errors/check_data_parse.c \
	checkers_errors/error_check.c \
	checkers_errors/error_check2.c \
	utils/get_floor_ceil.c \
	utils/hook_utils.c\
	utils/hook_utils2.c\
	utils/get_sprite.c\
	utils/direction_player.c\
	utils/sprite_utils.c\
	utils/screenshot.c\
	utils/cub_utils.c\
	utils/utils.c\
	utils/utils2.c\
	include/gnl/get_next_line.c \
	include/gnl/get_next_line_utils.c \

SRC = $(SRCS)

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):  $(OBJ)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	cp $(MLX_DIR)libmlx.dylib ./
	cp $(LIBFT_DIR)libft.a ./
	$(CC) $(INCLUDES) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT_DIR) clean
	rm -f *.bmp
	cd $(MLX_DIR) && make clean


fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	rm -f libft.a
	rm -f libmlx.dylib

re: fclean all

.PHONY: all clean fclean run re
