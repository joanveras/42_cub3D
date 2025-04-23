NAME = cube3D.a

SRCS =	$(wildcard sources/*.c) \
		$(wildcard sources/libft/*.c) \
		$(wildcard sources/get_next_line/*.c) \
		$(wildcard sources/utils/*.c) \
		$(wildcard sources/utils/helper/*.c) \
		$(wildcard sources/utils/input_keys/*.c) \
		$(wildcard sources/utils/file_validations/*.c) \
		$(wildcard sources/utils/raycasting/wall_casting/*.c)

BONUS_SRCS =	$(wildcard sources/bonus/*.c) \
				$(wildcard sources/bonus/raycasting/ceilling_floor_casting/*.c)

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

### Colors ############################################

GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RED = \033[0;31m
NC = \033[0m # No Color

### Rules #############################################

$(NAME): $(OBJS)
	@echo -e "${BLUE}Creating archive $(NAME)...${NC}"
	@ar rc $(NAME) $(OBJS)
	@echo -e "${BLUE}Compiling executable cube3D...${NC}"
	@$(CC) $(CFLAGS) -g main.c $(SRCS) -L minilibx-linux -lmlx_Linux -o cube3D -lX11 -lXext -lm
	@echo -e "${GREEN}Compilation finished.${NC}"

bonus: $(NAME) $(BONUS_OBJS)
	@echo -e "${BLUE}Creating archive $(NAME) with bonus...${NC}"
	@ar rc $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo -e "${BLUE}Compiling executable bonus_cube3D...${NC}"
	@$(CC) $(CFLAGS) -fsanitize=address -g bonus_main.c $(SRCS) $(BONUS_SRCS) -L minilibx-linux -lmlx_Linux -o bonus_cube3D -lX11 -lXext -lm
	@echo -e "${GREEN}Bonus compilation finished.${NC}"

%.o: %.c
	@echo -e "${YELLOW}Compiling $<...${NC}"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@echo -e "${YELLOW}Cleaning object files...${NC}"
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo -e "${GREEN}Object files cleaned.${NC}"

fclean: clean
	@echo -e "${YELLOW}Cleaning all generated files...${NC}"
	@$(RM) $(NAME)
	@$(RM) cube3D bonus_cube3D
	@echo -e "${GREEN}All generated files cleaned.${NC}"

re: fclean all

minilibx:
	@echo -e "${YELLOW}Downloading and extracting minilibx...${NC}"
	@wget https://cdn.intra.42.fr/document/document/25875/minilibx-linux.tgz
	@tar -xvzf minilibx-linux.tgz
	@$(RM) minilibx-linux.tgz
	@$(MAKE) -C minilibx-linux
	@echo -e "${GREEN}minilibx setup completed.${NC}"

.PHONY: all clean fclean re bonus
