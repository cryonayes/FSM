NAME	:= main

SRC		:= main.c
OBJ		:= $(SRC:%.c=%.o)

CC		:= gcc
CFLAGS	:= -lreadline -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
