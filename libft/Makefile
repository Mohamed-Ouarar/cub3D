CC          			= cc
CFLAGS      			= -Wall -Wextra -Werror
AR          			= ar rcs
NAME        			= libft.a

_ALLOCATE               = allocate/
_CHAR_C                 = character_checks/
_GNL                    = get_next_line/
_MEM_M                  = memory_management/
_OUTPUT_F               = output_functions/
_STR_M                  = string_manipulation/
_STR_T                  = string_transformations/
_HEADERS				= include/
_OBJS_DIR				= obj/

HEADERS					= $(_HEADERS)libft.h $(_HEADERS)get_next_line.h $(_HEADERS)ft_allocate.h 
SRCS             		= $(_ALLOCATE)ft_allocate.c $(_ALLOCATE)ft_allocate_action.c \
	$(_ALLOCATE)ft_allocate_utils.c 
SRCS			        += $(_STR_M)ft_strlen.c $(_STR_M)ft_strlcpy.c $(_STR_M)ft_strlcat.c \
	$(_STR_M)ft_strchr.c $(_STR_M)ft_strrchr.c $(_STR_M)ft_strncmp.c $(_STR_M)ft_strnstr.c \
	$(_STR_M)ft_strdup.c $(_MEM_M)ft_memcpy.c 
SRCS					+= $(_STR_T)ft_toupper.c $(_STR_T)ft_tolower.c $(_STR_T)ft_strtrim.c \
	$(_STR_T)ft_substr.c $(_STR_T)ft_strjoin.c $(_STR_T)ft_itoa.c $(_STR_T)ft_strmapi.c \
	$(_STR_T)ft_striteri.c $(_STR_T)ft_atoi.c $(_STR_T)ft_split.c $(_MEM_M)ft_memcpy.c \
	$(_STR_M)ft_strlen.c $(_STR_M)ft_strdup.c 
SRCS					+= $(_MEM_M)ft_memset.c $(_MEM_M)ft_memcpy.c $(_MEM_M)ft_memmove.c \
	$(_MEM_M)ft_bzero.c $(_MEM_M)ft_memchr.c $(_MEM_M)ft_memcmp.c $(_MEM_M)ft_calloc.c
SRCS					+= $(_CHAR_C)ft_isalpha.c $(_CHAR_C)ft_isdigit.c \
	$(_CHAR_C)ft_isalnum.c $(_CHAR_C)ft_isascii.c $(_CHAR_C)ft_isprint.c
SRCS					+= $(_OUTPUT_F)ft_putchar_fd.c $(_OUTPUT_F)ft_putstr_fd.c \
	$(_OUTPUT_F)ft_putendl_fd.c $(_OUTPUT_F)ft_putnbr_fd.c
SRCS					+= $(_GNL)get_next_line.c $(_GNL)get_next_line_utils.c 

RESET					= \033[0m
GREEN					= \033[1;32m
YELLOW					= \033[4;33m
BLUE					= \033[1;34m
RED						= \033[1;31m
GRAYL					= \033[3;90m
PURPLE					= \033[1;35m
BOLD					= \033[1m

OBJS = $(SRCS:%.c=$(_OBJS_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	printf "\n$(GREEN)Library $(YELLOW)$(NAME)$(RESET) $(GREEN)created successfully!$(RESET)\n"

$(_OBJS_DIR)%.o: %.c $(HEADERS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	printf "                                                      "
	printf "\r $(BLUE)Compiling: > $(RESET)$(GRAYL)$<$(RESET)"

clean:
	rm -rf $(_OBJS_DIR)
	echo "$(RED)Cleaned object files.$(RESET)"

fclean:
	rm -rf $(_OBJS_DIR)
	rm -f $(NAME) 
	echo "$(RED)Cleaned object files and libft.$(RESET)"

# Rebuild everything
re: fclean all

.SILENT: