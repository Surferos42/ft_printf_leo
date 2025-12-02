# Nazwa pliku wykonywalnego
TARGET = program

# Kompilator
CC = gcc

# Flagi kompilatora
CFLAGS = -Wall -Wextra -std=c99

# Pliki źródłowe
SRC = main.c process.c

# Domyślna akcja make
all: $(TARGET)

# Budowanie programu
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Czyszczenie pliku wykonywalnego
clean:
	rm -f $(TARGET)

# Kompilacja i uruchomienie
run: $(TARGET)
	./$(TARGET)

