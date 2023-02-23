#include <gamefield.h>

#include <stdio.h>
#include <stdlib.h>

#include <curses.h>

struct GameField* gamefield_init()
{
    struct GameField* gamefield = malloc(sizeof(struct GameField));
    if (gamefield == NULL)
        return NULL;
    int plate_num = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            gamefield->field[i][j] = plate_num;
            plate_num++;
        }
    }
    gamefield->field[3][3] = 0;
    gamefield->blank_tile = (struct Point){3, 3};

    return gamefield;
}

void gamefield_free(struct GameField* gamefield)
{
    free(gamefield);
}

void gamefield_print(struct GameField* gamefield)
{
    for (int i = 0; i < 4; i++) {
        printw("-------------\n");
        for (int j = 0; j < 4; j++) {
            addch('|');
            if (gamefield->field[i][j] == 0) {
                addch(' ');
            } else {
                printw("%d", gamefield->field[i][j]);
            }
            if (gamefield->field[i][j] < 10) {
                addch(' ');
            }
        }
        addch('|');
        addch('\n');
    }
    printw("-------------\n");
    refresh();
}

bool gamefield_swap(struct GameField* gamefield, struct Point direction)
{
    struct Point old_blank = gamefield->blank_tile;
    struct Point new_blank;
    new_blank.x = old_blank.x + direction.x;
    new_blank.y = old_blank.y + direction.y;

    if ((new_blank.x > 3 || new_blank.y > 3)) {
        return false;
    }
    if ((new_blank.x < 0 || new_blank.y < 0)) {
        return false;
    }

    gamefield->field[old_blank.y][old_blank.x]
            = gamefield->field[new_blank.y][new_blank.x];
    gamefield->field[new_blank.y][new_blank.x] = 0;

    gamefield->blank_tile = new_blank;
    return true;
}

void gamefield_shuffle(struct GameField* gamefield)
{
    struct Point directions[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    /*
    Directions here is similar to UP, DOWN, LEFT, RIGHT from main.c
    */

    int swaps = 1000;

    for (int i = 0; i < swaps; i++) {
        int direction_idx = rand() % 4;
        gamefield_swap(gamefield, directions[direction_idx]);
    }
}