NAME    = philo_bonus
CC      = gcc
FLAGS	= -Wall -Wextra -Werror
CFLAGS  = -pthread -D COLORED_TEXT
SRCDIR	=	src/
SRCFILE	= 	main.c\
			input_checker.c\
			start_philo.c\
			philo_process.c\
			philo_lifecycle.c\
			wait_philo_status.c\
			utils.c\
			ft_atoi.c\
			ft_isdigit.c
SRCS	= $(addprefix $(SRCDIR), $(SRCFILE))
OBJDIR	= obj/
OBJFILE = $(SRCFILE:.c=.o)
OBJMAIN = $(addprefix $(OBJDIR), $(MAIN:.c=.o))
OBJBNS	= $(addprefix $(OBJDIR), $(BONUS:.c=.o))
OBJS	= $(addprefix $(OBJDIR), $(OBJFILE))
RM      = rm -rf
PHILHDR = philo_bonus.h

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c $(MSHHDR)
	@mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) $(CFLAGS) -c $< -o $@ -include $(PHILHDR)
	@printf "\033[1;36m/\033[0m"

$(NAME): $(OBJS) $(OBJMAIN) $(MSHHDR)
	@echo
	@echo "\033[1;33m"$(NAME) "objs is up to date."'\033[0m'
	@$(CC) $(FLAGS) $(CFLAGS) $(LFLAGS) $(OBJS) $(OBJMAIN) $(LFLAGS) -o $(NAME)
	@echo "\033[1;33m"$(NAME) "is up to date."'\033[0m'

clean:
	@$(RM) $(OBJDIR)
	@echo '\033[1;31m'$(NAME) "objs deleted."'\033[0m'

fclean: clean
	@$(RM) $(NAME)
	@echo '\033[1;31m'$(NAME) "deleted."'\033[0m'

re: fclean all

.PHONY: all clean fclean re bonus
