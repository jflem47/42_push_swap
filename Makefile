NAME			=	push_swap

CC				=	gcc -g
CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -rf

SRCS 			=	src/main.c \
					src/push_swap.c \
					src/utils/parsing.c \
					src/utils/utils.c \
					src/utils/operations_1.c \
					src/utils/operations_2.c \
					src/utils/operations_3.c \
					src/debug/debug.c \
					src/algos/small_size.c \
					src/algos/large_size.c \
					src/utils/index_utils.c \
					src/algos/small_sort.c \
					src/algos/large_sort.c \
					src/utils/algo_utils.c \

OBJS			=	$(SRCS:%.c=%.o)

LIBS			= 	$(LIBFT) $(FT_PRINTF)

INCLUDES 		=	-I $(LIBFT_PATH) -I $(FT_PRINTF_PATH) -I ./include

LIBFT_PATH		=	./lib/libft
FT_PRINTF_PATH	=	./lib/ft_printf
LIBFT			=	$(LIBFT_PATH)/libft.a
FT_PRINTF 		=	$(FT_PRINTF_PATH)/libftprintf.a

all:	$(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

$(NAME): $(FT_PRINTF) $(OBJS) ./include/push_swap.h
	$(info Compiling push_swap...)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) $(INCLUDES)
	@echo "\033[0;32mAll done ! Have fun sorting !\033[0m"

$(FT_PRINTF):
	$(info Compiling libft...)
	@make -C $(FT_PRINTF_PATH) all

clean:
	$(info Cleaning up...)
	@make -C $(FT_PRINTF_PATH) clean
	@$(RM) $(OBJS)

fclean:	clean
	@make -C $(FT_PRINTF_PATH) fclean
	@$(RM) $(NAME)

re:					fclean all

.PHONY:				all bonus clean fclean re libft