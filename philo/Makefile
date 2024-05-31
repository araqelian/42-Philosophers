NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
RED="\033[0;31m"
YELLOW="\033[0;33m"

NAME = philo

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.c)

OBJS = $(patsubst %.c, %.o, $(SRCS))

RM = rm -f

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJS)
	@echo $(NONE)$(YELLOW) "\t\t🤹 Compiling $(NAME)..." $(NONE)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@echo $(NONE)$(GREEN)"\t\t😱 Compiled   $(NAME)\n"$(NONE)

clean:
	@echo $(RED) "\t\t🙀 Removing object files..." $(NONE)
	@$(RM) $(OBJS)

fclean: clean
	@echo $(RED) "\t\t🙀 Removing $(NAME)..." $(NONE)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
