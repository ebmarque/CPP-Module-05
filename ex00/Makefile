# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/05 13:49:26 by ebmarque          #+#    #+#              #
#    Updated: 2024/06/05 13:53:01 by ebmarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRC_DIR = sources
SRCS = $(addprefix $(SRC_DIR)/, main.cpp Bureaucrat.cpp)
OBJS = $(addprefix OBJS/, $(notdir $(SRCS:.cpp=.o)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

OBJS/%.o: %.cpp
	mkdir -p OBJS
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf OBJS $(NAME)

.PHONY: all clean