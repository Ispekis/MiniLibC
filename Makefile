##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	src/memcpy.asm		\
		src/strlen.asm		\
		src/strchr.asm		\
		src/strrchr.asm		\
		src/strcmp.asm		\
		src/memmove.asm		\
		src/strncmp.asm		\
		src/strcasecmp.asm	\
		src/memset.asm		\
		src/strstr.asm		\
		src/strpbrk.asm		\
		src/strcspn.asm		\
		src/index.asm		\
		src/rindex.asm

TEST_FILES	=	tests/test_project.c

NAME	=	libasm.so

TEST_NAME	=	unit_tests

OBJ		=	$(SRC:.asm=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ld -fPIC -shared -o $(NAME) $(OBJ)

tests_run:	all
	$(CC) $(TEST_FILES) -o $(TEST_NAME) -lcriterion --coverage -ldl
	./${TEST_NAME}
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

%.o : %.asm
		nasm -f elf64 -o $@ $<

clean:
	$(RM) $(OBJ)
	$(RM) *.gcno
	$(RM) *.gcda

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)

re:	fclean all

.PHONY: all clean fclean re tests_run
