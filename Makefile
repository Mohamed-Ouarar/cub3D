CC					= cc
CFLAGS				= -Wall -Wextra -Werror -fsanitize=address -g
LDFLAGS 			= -lmlx -framework OpenGL -framework AppKit

NAME				= cub3D

OBJ_DIR				= obj/
LIBFT_OBJDIR		= $(OBJ_DIR)libft/
SRC_OBJDIR			= $(OBJ_DIR)mandatory/srcs/

INC_DIR				= mandatory/includes/
LIBFT_INC_DIR		= libft/include/

RED					= \033[0;31m
GREEN				= \033[0;32m
YELLOW				= \033[0;33m
BLUE				= \033[0;34m
PURPLE				= \033[0;35m
CYAN				= \033[0;36m
WHITE				= \033[0;37m
BOLD				= \033[1m
RESET				= \033[0m

HEADERS				= $(INC_DIR)cub3d.h $(INC_DIR)parsing.h $(INC_DIR)render.h 
LIBFT_HEADERS		= $(LIBFT_INC_DIR)ft_allocate.h $(LIBFT_INC_DIR)get_next_line.h \
						$(LIBFT_INC_DIR)libft.h

LIBFT_SRCS = \
	libft/allocate/ft_allocate.c \
	libft/allocate/ft_allocate_action.c \
	libft/allocate/ft_allocate_utils.c \
	libft/string_manipulation/ft_strlen.c \
	libft/string_manipulation/ft_strlcpy.c \
	libft/string_manipulation/ft_strlcat.c \
	libft/string_manipulation/ft_strchr.c \
	libft/string_manipulation/ft_strrchr.c \
	libft/string_manipulation/ft_strncmp.c \
	libft/string_manipulation/ft_strnstr.c \
	libft/string_manipulation/ft_strdup.c \
	libft/string_transformations/ft_toupper.c \
	libft/string_transformations/ft_tolower.c \
	libft/string_transformations/ft_strtrim.c \
	libft/string_transformations/ft_substr.c \
	libft/string_transformations/ft_strjoin.c \
	libft/string_transformations/ft_itoa.c \
	libft/string_transformations/ft_strmapi.c \
	libft/string_transformations/ft_striteri.c \
	libft/string_transformations/ft_atoi.c \
	libft/string_transformations/ft_split.c \
	libft/memory_management/ft_memset.c \
	libft/memory_management/ft_memcpy.c \
	libft/memory_management/ft_memmove.c \
	libft/memory_management/ft_bzero.c \
	libft/memory_management/ft_memchr.c \
	libft/memory_management/ft_memcmp.c \
	libft/memory_management/ft_calloc.c \
	libft/character_checks/ft_isalpha.c \
	libft/character_checks/ft_isdigit.c \
	libft/character_checks/ft_isalnum.c \
	libft/character_checks/ft_isascii.c \
	libft/character_checks/ft_isprint.c \
	libft/output_functions/ft_putchar_fd.c \
	libft/output_functions/ft_putstr_fd.c \
	libft/output_functions/ft_putendl_fd.c \
	libft/output_functions/ft_putnbr_fd.c \
	libft/get_next_line/get_next_line.c \
	libft/get_next_line/get_next_line_utils.c

SRCS = \
	mandatory/srcs/main.c \
	mandatory/srcs/parsing/pasing.c \
	mandatory/srcs/parsing/pasing_textures.c \
	mandatory/srcs/parsing/pasing_colors.c \
	mandatory/srcs/cleanup/error_msg.c \
	mandatory/srcs/utils/parsing_utils.c 

LIBFT_OBJS = $(LIBFT_SRCS:%.c=$(OBJ_DIR)%.o)
OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(LIBFT_OBJS) $(OBJS)
	$(CC) $(LIBFT_OBJS) $(OBJS) $(LDFLAGS) $(CFLAGS) -o $(NAME)
	printf "\n$(GREEN)$(BOLD)✅ Successfully built $(CYAN)$(NAME)$(RESET)\n"

$(OBJ_DIR)libft/%.o: libft/%.c $(LIBFT_HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	printf "\r                                                                   "
	printf "\r$(BLUE)🔧 $(PURPLE)[libft]$(RESET) > Compiling: $(YELLOW)$<$(RESET)\n"

$(OBJ_DIR)mandatory/srcs/%.o: mandatory/srcs/%.c $(HEADERS) $(LIBFT_HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	printf "\r                                                                   "
	printf "\r$(BLUE)🔧 $(CYAN)[src]$(RESET)   > Compiling: $(YELLOW)$<$(RESET)\n"

clean:
	rm -rf $(OBJ_DIR)
	printf "$(RED)🧹 Cleaned object files$(RESET)\n"

fclean: clean
	rm -f $(NAME)
	printf "$(RED)🧹 Cleaned binary $(CYAN)$(NAME)$(RESET)\n"

re: fclean all
	printf "$(GREEN)$(BOLD)🔄 Rebuild complete!$(RESET)\n"

.SILENT: