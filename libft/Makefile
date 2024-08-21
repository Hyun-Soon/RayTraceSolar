NAME		= libft.a

CC			= cc
CFLAG		= -Wall -Wextra -Werror

RM			= rm -f

AR			= ar
ARFLAGS		= rs

INCLUDES	= ./libft.h

PART_1		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isspace.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strncmp.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_strndup.c

PART_2		= ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCS		= $(PART_1) $(PART_2) ft_format.c ft_printf.c ft_putnbr.c get_next_line.c get_next_line_utils.c


OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^

%.o : %.c $(INCLUDES)
	@$(CC) $(CFLAG) -c $< -o $@

clean :
	@$(RM) $(SRCS:.c=.o)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
