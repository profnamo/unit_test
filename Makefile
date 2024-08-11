CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lcheck -lsubunit -lm

TARGET = test_math_functions

SRC = math_functions.c
TEST_SRC = test_math_functions.c

$(TARGET): $(SRC) $(TEST_SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(TEST_SRC) $(LDFLAGS)

clean:
	rm -f $(TARGET)
