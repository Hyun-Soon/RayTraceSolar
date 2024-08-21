#-------------------------------------------

BLACK       =   "\033[0;30m"
GRAY        =   "\033[1;30m"
RED         =   "\033[1;31m"
GREEN       =   "\033[0;32m"
YELLOW      =   "\033[1;33m"
PURPLE      =   "\033[0;35m"
CYAN        =   "\033[1;36m"
WHITE       =   "\033[1;37m"
EOC         =   "\033[0;0m"
LINE_CLEAR  =   "\x1b[1A\x1b[M"

#-------------------------------------------

NAME = miniRT
CC = cc
MLX = -lmlx -framework OpenGL -framework Appkit
CFLAGS = -I./include  -Wall -Wextra -Werror
SRCS = ./src/main.c \
		./src/init.c \
		./src/vec3_utils.c \
		./src/vec3_ari_ops.c \
		./src/vec3_rotation.c \
		./src/vec3_vec_ops.c \
		./src/ray.c \
		./src/object_create.c \
		./src/object_create2.c \
		./src/utils.c \
		./src/object_utils.c \
		./src/phong_lighting.c \
		./src/map_parse.c \
		./src/map_parse_objs.c \
		./src/map_parse_bonus_objs.c \
		./src/map_parse_planet.c \
		./src/print.c \
		./src/key_hook.c \
		./src/check_keys.c \
		./src/planet_utils.c \
		./src/teleport.c \
		./src/parse_utils.c \
		./src/parse_utils2.c \
		./src/anti_aliasing.c \
		./src/hit/hit.c \
		./src/hit/hit_sphere.c \
		./src/hit/hit_sphere_utils.c \
		./src/hit/hit_plane.c \
		./src/hit/hit_cone.c \
		./src/hit/hit_cylinder.c \
		./src/hit/hit_checkerboard.c \
		./src/hit/hit_planet.c \

OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(MLX) -o $(NAME) $^
	@echo $(GREEN)"\n==========================================================\n"$(EOC)
	@echo $(YELLOW)"                    miniRT is ready"$(EOC)
	@echo $(GREEN)"\n==========================================================\n"$(EOC)

$(LIBFT) :
	@cd libft ; $(MAKE)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
	cd libft ; $(MAKE) clean

fclean : clean
	rm -f $(NAME)
	cd libft ; $(MAKE) fclean

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all bonus clean fclean re
