# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 18:06:24 by amagnell          #+#    #+#              #
#    Updated: 2023/12/08 21:28:25 by amagnell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------------------------------------------#
#	TARGET				    #
#-------------------------------------------#
NAME := push_swap

#-------------------------------------------#
#	INGREDIENTS			    #
#-------------------------------------------#
LIBS		:=	ft
LIBS_FOLDER	:=	lib/libft
LIBS_TARGET	:=	libft/libft.a

INCS		:=	include	\
			libft/include

SRC_DIR		:=	src
SRCS 		:=	src/push_swap.c \
			src/named_operations.c \
			src/named_operations2.c \
			src/named_operations3.c \
			src/parsing_utils.c \
			src/stack_operations.c \
			src/list_utils.c \
			src/list_utils2.c \
			src/sorting_utils.c

BUILD_DIR 	:=	.build
OBJS		:=	$(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:=	$(OBJS:%.o=%.d)

CC 			:=	clang
CFLAGS 		:=	-Wall -Wextra -Werror
CPPFLAGS 	:=	$(addprefix -I, $(INCS)) -MMD -MP
LDFLAGS		:=	$(addprefix -L, $(dir $(LIBS_TARGET)))
LDLIBS		:=	$(addprefix -l, $(LIBS))

#-------------------------------------------#
#	UTILS				    #
#-------------------------------------------#
RM 			:=	rm -f
MAKEFLAGS += --no-print-directory
DIR_DUP		=	mkdir -p $(@D)

#-------------------------------------------#
#	RECIPES				    #
#-------------------------------------------#
all: libft $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@
	$(info Created $@)

libft:
	$(MAKE) -C $(LIBS_FOLDER)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info Created $@)

-include $(DEPS)

clean:
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f fclean; done
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

#-------------------------------------------#
#	SPECIAL RULES			    #
#-------------------------------------------#

.PHONY: all re clean fclean libft
.SILENT:
