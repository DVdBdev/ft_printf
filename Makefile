NAME			=	libftprintf.a
CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra
RM				=	rm -rf
AR				=	ar rcs

SRC				=	ft_printf printf_char printf_hex printf_int \
					printf_percent printf_pointer printf_string \
					printf_unsigned_int \

SRCS			=	$(addsuffix .c, $(SRC))

OBJ_DIR			= 	obj
OBJS			=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

COLOR_DEFAULT = \033[0m
COLOR_GREEN   = \033[32m
COLOR_BLUE    = \033[34m
COLOR_CYAN    = \033[36m
COLOR_RED 	  = \033[0;31m

$(OBJ_DIR)/%.o:	%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(COLOR_GREEN)Compiling: $(COLOR_CYAN)$<$(COLOR_DEFAULT)"

all: $(OBJ_DIR) $(NAME)
	@echo "$(COLOR_GREEN)ft_printf compiled!$(COLOR_DEFAULT)"

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(AR) $(NAME) $(OBJS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(COLOR_RED)Removing: $(COLOR_CYAN)object files$(COLOR_DEFAULT)"

fclean:	clean
	@$(RM) $(NAME)
	@echo "$(COLOR_RED)Removing: $(COLOR_CYAN)executable files$(COLOR_DEFAULT)"
	@echo "$(COLOR_RED)ft_printf fcleaned!$(COLOR_DEFAULT)"

re:	fclean all
	@echo "$(COLOR_GREEN)Cleaned and rebuilt everything for ft_printf!$(COLOR_DEFAULT)"

.PHONY: all clean fclean re