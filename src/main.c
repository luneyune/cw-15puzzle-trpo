#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <unistd.h>

#include <gamefield.h>

// Swapping directions
const struct Point UP = {0, 1};
const struct Point DOWN = {0, -1};
const struct Point LEFT = {1, 0};
const struct Point RIGHT = {-1, 0};
/*
NOTE: They are inverted due to tech requirement decision.
For more check
https://github.com/luneyune/cw-15puzzle-trpo/wiki/Tech-requirement "Управление".
*/

int main()
{
    initscr();
    cbreak();

    srand(time(NULL));

    struct GameField* gamefield = gamefield_init();
    gamefield_print(gamefield);

    gamefield_shuffle(gamefield);
    gamefield_print(gamefield);

    gamefield_free(gamefield);

    getch();
    endwin();
}