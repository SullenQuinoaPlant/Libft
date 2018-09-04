ifndef ROOT
	ROOT = .
endif

include $(ROOT)/targets.mk

NAME = libft
A_NAME = $(NAME).a
SO_NAME = $(NAME).so

SRCS = $(patsubst %,$(SRC_DIR)/%.c,$(TARGETS))
OBJS = $(patsubst %.c,%.o,$(SRCS))

TEST_DIR := $(ROOT)/tests
SRC_DIR := $(ROOT)/sources
OBJ_DIR := $(ROOT)/objects

GCCFLAGS := -Wall -Wextra -Werror
