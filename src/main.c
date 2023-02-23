#include <stdio.h>

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
    struct GameField* gamefield = gamefield_init();
    gamefield_print(gamefield);

    gamefield_swap(gamefield, DOWN);
    gamefield_print(gamefield);

    gamefield_swap(gamefield, RIGHT);
    gamefield_print(gamefield);

    gamefield_swap(gamefield, LEFT);
    gamefield_print(gamefield);

    gamefield_swap(gamefield, UP);
    gamefield_print(gamefield);

    gamefield_free(gamefield);
}