NAME = so_long

BONUS = so_long_bonus

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

CFILES = so_long.c \
		 so_long_uti.c \
		 check_map.c \
		 map_uti.c \
		 get_next_line.c \
		 get_next_line_utils.c \
		 path.c \
		 move.c \
		 move_uti.c \
		 put_image.c \
		 put_image_uti.c \

CBONUS = bonus/so_long_bonus.c \
		 bonus/so_long_uti_bonus.c \
		 bonus/check_map_bonus.c \
		 bonus/map_uti_bonus.c \
		 bonus/get_next_line_bonus.c \
		 bonus/get_next_line_utils_bonus.c \
		 bonus/path_bonus.c \
		 bonus/move_bonus.c \
		 bonus/move_uti_bonus.c \
		 bonus/put_image_bonus.c \
		 bonus/put_image_uti_bonus.c \
		 bonus/ft_itoa_bonus.c \
		 bonus/libft_bonus.c \
		 bonus/path_uti_bonus.c \
		 bonus/enemy_bonus.c \
		 bonus/check_file_bonus.c \

OBJ = so_long.o \
	  so_long_uti.o \
	  check_map.o \
	  map_uti.o \
	  get_next_line.o \
	  get_next_line_utils.o \
	  path.o \
	  move.o \
	  move_uti.o \
	  put_image.o \
	  put_image_uti.o \

OBONUS = bonus/so_long_bonus.o \
		 bonus/so_long_uti_bonus.o \
		 bonus/check_map_bonus.o \
		 bonus/map_uti_bonus.o \
		 bonus/get_next_line_bonus.o \
		 bonus/get_next_line_utils_bonus.o \
		 bonus/path_bonus.o \
		 bonus/move_bonus.o \
		 bonus/move_uti_bonus.o \
		 bonus/put_image_bonus.o \
		 bonus/put_image_uti_bonus.o \
		 bonus/ft_itoa_bonus.o \
		 bonus/libft_bonus.o \
		 bonus/path_uti_bonus.o \
		 bonus/enemy_bonus.o \
		 bonus/check_file_bonus.o \

all : $(NAME)

$(NAME) : $(OBJ)

	 cc -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

bonus : $(BONUS)

$(BONUS) : $(OBONUS)
	cc -lmlx -framework OpenGL -framework AppKit $(OBONUS) -o $(BONUS)

clean :
	$(RM) $(OBJ) $(OBONUS)

fclean : clean
	$(RM) $(NAME) $(BONUS)

re : fclean all
