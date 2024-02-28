NAME = cub3D

CFLAGS = -Wextra -Wall -Werror -g -O3

CC = gcc

LIB = lib

OBJ_DIR = obj/

SRC_DIR = src/

LIBMLX := ./lib/MLX42

HEADERS := -I ./include -I $(LIBMLX)/include

SRC := main.c setup.c rays.c init.c render.c rays_utils.c parsing.c \
		main_utils.c p_colors.c p_ids.c p_maps.c p_maps2.c p_maps3.c \
		p_colors2.c parsing_utils.c \

OBJ = $(SRC:.c=.o)
SRCS = $(addprefix $(SRC_DIR), $(SRC))


OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

LIBS = $(LIBMLX)/build/libmlx42.a

LDFLAGS := -ldl -lglfw -pthread -lm -flto -framework Cocoa -framework OpenGL -framework IOKit

LBFT = ./libft/libft.a


all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) -c $< -o $@ $(CFLAGS) $(HEADER)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@cd libft && make
	@mkdir lib && cd lib && git clone https://github.com/codam-coding-college/MLX42.git
	@cd lib/MLX42 && cmake -B build && cmake --build build -j4
	@clear


$(NAME): $(OBJS)
	@echo "Building..."
	@$(CC) $(CFLAGS) $(OBJS) $(LBFT) $(LIBS) $(HEADERS) $(LDFLAGS) -o $(NAME)

install_brew:
	@echo "installing brew.." \
	@rm -rf $HOME/.brew && rm -rf $HOME/goinfre/.brew && \
	@git clone --depth=1 https://github.com/Homebrew/brew $HOME/goinfre/.brew && \
	@echo 'export PATH=$HOME/goinfre/.brew/bin:$PATH' >> $HOME/.zshrc && \
	@source $HOME/.zshrc && brew update \

install_glfw:
	@echo "installing glfw.."
	brew install glfw

install: install_brew install_glfw

clean:
	@echo "Cleaning.."
	@cd libft && make clean
	@rm -rf $(OBJ_DIR)
	@rm -rf ./lib
	@clear

fclean: clean
	@echo "Full Cleaning.."
	@cd libft && make fclean
	@rm -rf $(NAME)
	@clear

re: fclean all

.PHONY: all clean fclean re
