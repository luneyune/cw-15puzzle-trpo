CFLAGS = -Wall -Werror -lcurses -I src
CC = gcc

Executable_dir = bin
Objects_app_dir = obj/app
Objects_test_dir = obj/test
Sources_app_dir = src
Sources_thirdpaty_dir = thirdpaty
Sources_test_dir = test

all: $(Executable_dir)/main

.PHONY: all run format test

#Executables
$(Executable_dir)/main: $(Objects_app_dir)/main.o $(Objects_app_dir)/gamefield.o 
	$(CC) $^ $(CFLAGS) -o $@

$(Executable_dir)/test_main: $(Objects_test_dir)/main.o $(Objects_test_dir)/gamefield_test.o $(Objects_app_dir)/gamefield.o
	$(CC) $^ $(CFLAGS) -o $@

#App objects
$(Objects_app_dir)/main.o: $(Sources_app_dir)/main.c $(Sources_app_dir)/gamefield.h 
	$(CC) $< $(CFLAGS) -c -o $@

$(Objects_app_dir)/gamefield.o: $(Sources_app_dir)/gamefield.c $(Sources_app_dir)/gamefield.h
	$(CC) $< $(CFLAGS) -c -o $@

#Test objects
$(Objects_test_dir)/main.o: $(Sources_test_dir)/main.c $(Sources_app_dir)/gamefield.h 
	$(CC) $< $(CFLAGS) -I $(Sources_thirdpaty_dir) -I $(Sources_test_dir) -c -o $@

$(Objects_test_dir)/gamefield_test.o: $(Sources_test_dir)/gamefield_test.c $(Sources_app_dir)/gamefield.h
	$(CC) $< $(CFLAGS) -I $(Sources_thirdpaty_dir) -I $(Sources_test_dir) -c -o $@

run: $(Executable_dir)/main
	$(Executable_dir)/main
clean:
	rm -f $(Objects_app_dir)/*.o
	rm -f $(Objects_test_dir)/*.o
	rm -f $(Executable_dir)/main $(Executable_dir)/test_main 
format:
	clang-format --style=file -i $(Sources_app_dir)/*.c $(Sources_app_dir)/*.h $(Sources_test_dir)/*.c
test: $(Executable_dir)/test_main
	$(Executable_dir)/test_main
