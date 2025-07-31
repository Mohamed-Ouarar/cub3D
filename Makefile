CC				= cc
CFLAGS			= -Wall -Wextra -Werror
LDFLAGS			= -lmlx -framework OpenGL -framework AppKit

### DIRECTORIES
INC_DIR			= includes
LIB_DIR			= libft
LIB_INC_DIR		= $(LIB_DIR)/include
SRC_DIR			= src
OBJS_DIR		= obj
# Subdirectories
PAR_DIR			= $(SRC_DIR)/parsing
INT_DIR			= $(SRC_DIR)/init
UTI_DIR			= $(SRC_DIR)/utils
CLE_DIR			= $(SRC_DIR)/cleanup
### EXECUTABLE
NAME			= cub3D
BONUS			= cub3D_bonus
### SOURCE FILES
SRCS 			= $(SRC_DIR)/main.c

### Substitution Reference 
OBJS            = $(SRCS:%.c=$(OBJS_DIR)/%.o)
### COLORS AND FORMATTING
RESET			= \033[0m
GREEN			= \033[1;32m
YELLOW			= \033[4;33m
BLUE			= \033[1;34m
RED				= \033[1;31m
GRAYL			= \033[3;90m

### RULES
### MAIN RULES
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(LIBFT_OBJS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "$(YELLOW) $(NAME) $(RESET) $(GREEN)created successfully!$(RESET)"

# Compile main program source files
$(OBJS_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.c \
	$(LIB_INC_DIR)/libft.h $(LIB_INC_DIR)/ft_allocate.h $(INC_DIR)/minishell.h 
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)Compiling $(GRAYL)$<...$(RESET)"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)Object files removed.$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)$(NAME) removed.$(RESET)"

re: fclean all