CFLAGS = -Wall -Werror -I src
CC = gcc

Executable_dir = bin
Objects_app_dir = obj
Sources_app_dir = src
Sources_thirdpaty_dir = thirdpaty

all: $(Executable_dir)/main

.PHONY: all run

#Executables
$(Executable_dir)/main: $(Objects_app_dir)/main.o
	$(CC) $^ $(CFLAGS) -o $@

#App objects
$(Objects_app_dir)/main.o: $(Sources_app_dir)/main.c
	$(CC) $< $(CFLAGS) -c -o $@

run:
	$(Executable_dir)/main

clean:
	rm -f $(Objects_app_dir)/*.o
	rm -f $(Executable_dir)/main
