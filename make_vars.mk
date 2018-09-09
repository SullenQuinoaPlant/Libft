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
INC_DIR := $(ROOT)/includes
OBJ_DIR := $(ROOT)/objects

CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)
SET_CFLAGS := $(CFLAGS)

A_STAMPS = was_liba is_liba
SO_STAMPS = was_libso is_libso
