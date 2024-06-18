##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile to compil the -lmy
##

NAME	=	libmy.a

SRC		=	concat_params.c				\
			convert_base.c 				\
			my_compute_power_rec.c 		\
			my_compute_square_root.c 	\
			my_find_prime_sup.c 		\
			my_float_len.c 				\
			my_getnbr.c 				\
			my_intlen.c 				\
			my_is_prime.c 				\
			my_isneg.c 					\
			my_itoa.c      				\
			my_longlen.c 				\
			my_put_exp.c 				\
			my_put_exp2.c 				\
			my_put_float.c 				\
			my_put_g.c 					\
			my_put_long.c 				\
			my_put_nbr.c 				\
			my_put_unsigned.c 			\
			my_putchar.c 				\
			my_putstr.c 				\
			my_revstr.c 				\
			my_show_word_array.c 		\
			my_sort_int_array.c 		\
			my_str_isalpha.c 			\
			my_str_islower.c 			\
			my_str_isnum.c 				\
			my_str_isprintable.c 		\
			my_str_isupper.c 			\
			my_str_to_word_array.c 		\
			my_strcat.c 				\
			my_strcmp.c 				\
			my_strcpy.c 				\
			my_strdup.c 				\
			my_strlen.c 				\
			my_strlowcase.c 			\
			my_strncat.c 				\
			my_strncmp.c 				\
			my_strncpy.c 				\
			my_strstr.c 				\
			my_strupcase.c 				\
			my_swap.c 					\
			my_unsignedlen.c			\
			my_unsigned_nbr.c 			\
			my_positive_nbr.c 			\
			my_printf.c 				\
			printf_i.c 					\
			printf_c.c 					\
			printf_d.c 					\
			printf_s.c 					\
			printf_u.c 					\
			printf_x.c 					\
			printf_xm.c 				\
			printf_o.c 					\
			printf_f.c 					\
			printf_fm.c 				\
			printf_cross.c 				\
			printf_l.c	 				\
			my_malloc.c					\
			my_strndup.c				\
			my_realloc.c				\
			my_tablen.c					\
			my_free_word_array.c 		\
			tok_to_word_array.c

OBJ 	= 	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		@$(AR) rc $(NAME) $(OBJ)
		@mv $(NAME) ../../
		@echo -e "\e[1;36m{ libmy.a ready and my.h duplicated !! }\e[00;37m"

clean:
		@$(RM) $(OBJ) *~

fclean: clean
		$(RM) ../../$(NAME)
		@echo -e "\e[1;33m[ libmy.a has been deleted ]\e[00;37m"

re: fclean all

.PHONY: all clean fclean re
