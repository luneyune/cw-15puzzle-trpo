#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <controls.h>
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

static int actions_number = 0;

bool game_action(enum Key key, struct GameField* gamefield)
{
    switch (key) {
    case UP_k:
        if (gamefield_swap(gamefield, UP)) {
            actions_number++;
        }
        return true;
    case DOWN_k:
        if (gamefield_swap(gamefield, DOWN)) {
            actions_number++;
        }
        return true;
    case LEFT_k:
        if (gamefield_swap(gamefield, LEFT)) {
            actions_number++;
        }
        return true;
    case RIGHT_k:
        if (gamefield_swap(gamefield, RIGHT)) {
            actions_number++;
        }
        return true;
    case QUIT_k:
        return false;
    case ERR_k:
        return true;
    }
    return false;
}

void win_message()
{
    erase();
    printw("Congratulation! you solved a puzzle in %d actions!\n",
           actions_number);
    printw("PRESS Q for quit or any other key for continue!\n");
    refresh();
}

int main()
{
    controls_setup();
    srand(time(NULL));

    struct GameField* gamefield = gamefield_init();
    gamefield_shuffle(gamefield);

    gamefield_print(gamefield);
    printw("Actions: %d\n", actions_number);
    printw("WASD - for swapping tiles\nPRESS Q for exit\n");
    refresh();

    enum Key key = controls_user_input();

    while (game_action(key, gamefield)) {
        if (gamefield_is_win(gamefield)) {
            win_message();
            key = controls_user_input();
            if (key == QUIT_k) {
                break;
            }
            actions_number = 0;
            gamefield_shuffle(gamefield);
        }

        erase();
        gamefield_print(gamefield);
        printw("Actions: %d\n", actions_number);
        printw("WASD - for swapping tiles\nPRESS Q for exit\n");
        refresh();
        key = controls_user_input();
    }

    gamefield_free(gamefield);
    controls_end();
}