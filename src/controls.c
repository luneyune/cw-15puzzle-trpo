#include <controls.h>

#include <curses.h>

void controls_setup()
{
    initscr();
    cbreak();
    noecho();
}

void controls_end()
{
    endwin();
}

enum Key controls_user_input()
{
    int key;
    key = getch();

    switch (key) {
    case UP_CHAR:
        return UP_k;
    case LEFT_CHAR:
        return LEFT_k;
    case RIGHT_CHAR:
        return RIGHT_k;
    case DOWN_CHAR:
        return DOWN_k;
    case QUIT_CHAR:
        return QUIT_k;
    }
    return ERR_k;
}