# C :=gcc
# CPP :=g++
# LDFLAGS :=
# C_SOURCES :=$(wildcard *.c)
# C_EXECUTABLE :=$(C_SOURCES:.c=)
# CPP_SOURCES :=$(wildcard *.cpp)
# CPP_EXECUTABLE :=$(CPP_SOURCES:.cpp=)
 
# all:$(C_EXECUTABLE) $(CPP_EXECUTABLE)

# $(C_EXECUTABLE):$(C_SOURCES)
# 		$(CC) $< $(LDFLAGS) $(CFLAGS) -o $@

# $(CPP_EXECUTABLE):$(CPP_SOURCES)
# 		$(CPP) $< $(LDFLAGS) $(CFLAGS) -o $@

# clean:
# 		rm -rf $(EXECUTABLE)

# CC=gcc
# CFLAGS=-std=c17 -Wall -Werror -pedantic -D_FORTIFY_SOURCE=2 -O1
# SRC=src
# BIN=bin

# SRCS=$(wildcard $(SRC)/*.c)
# BINS=$(SRCS:$(SRC)/%.c=%)

# all: $(BINS)

# %: $(SRC)/%.c
# 	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

# clean:
# 	$(RM) $(BIN)/*

CC := g++
CFLAGS := -Wall -g
TARGET := test

# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SRCS := $(wildcard *.cpp)
# $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<
clean:
	rm -rf $(TARGET) *.o
	
.PHONY: all clean

