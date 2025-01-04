NAME = push_swap

SRC = main.c operation_set1.c operation_set2.c operation_set3.c operation_utils.c ft_atol.c ft_sort.c ft_sort_three.c
OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)
FT_PRINTF = 010_FT_PRINTF/libftprintf.a
LIBFT = 020_LIBFT/libft.a

CCA = cc -Wall -Werror -Wextra -g3 -MP -MMD

MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJ)
	@$(CCA) -o $(NAME) $(OBJ) $(LIBFT) $(FT_PRINTF)

$(FT_PRINTF):
	@$(MAKE) -C 010_FT_PRINTF/

$(LIBFT):
	@$(MAKE) -C 020_LIBFT/

%.o: %.c
	@$(CCA) -o $@ -c $<

clean:
	@$(MAKE) clean -C 010_FT_PRINTF/
	@$(MAKE) clean -C 020_LIBFT/
	@rm -f $(OBJ) $(DEP)

fclean:
	@$(MAKE) fclean -C 020_LIBFT/
	@$(MAKE) fclean -C 010_FT_PRINTF/
	@rm -f $(OBJ) $(DEP) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)
