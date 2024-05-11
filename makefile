CC = gcc
CFLAGS = -Wall
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
TEST_DIR = test

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

TEST_SRCS := $(wildcard $(TEST_DIR)/check_*.c)
TEST_TARGETS := $(patsubst $(TEST_DIR)/%.c, $(BIN_DIR)/%, $(TEST_SRCS))

all: dirmake $(OBJS)

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/%: $(BUILD_DIR)/%.o
	$(CC) $(CFLAGS) $^ -o $@

dirmake:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BIN_DIR)

.PHONY: check

check: dirmake $(BIN_DIR) $(TEST_TARGETS) 
	@for target in $(TEST_TARGETS); do \
		$$target; \
	done

$(BIN_DIR)/%: $(TEST_DIR)/%.c $(OBJS)
	$(CC) $(CFLAGS) $< $(OBJS) -o $@ -lm -lcheck -lsubunit

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)/*.o $(BIN_DIR)/*

.PHONY: all