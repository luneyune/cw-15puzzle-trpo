#ifndef CW_15PUZZLE_TRPO_SRC_GAMEFIELD_H_
#define CW_15PUZZLE_TRPO_SRC_GAMEFIELD_H_

#include <stdbool.h>

struct Point {
    int x;
    int y;
};

struct GameField {
    int field[4][4];
    struct Point blank_tile;
};

// Memory control functions
struct GameField* gamefield_init();
void gamefield_free(struct GameField* gamefield);

// Output functions
void gamefield_print(struct GameField* gamefield);

// Tiles manipulation functions
bool gamefield_swap(struct GameField* gamefield, struct Point direction);
void gamefield_shuffle(struct GameField* gamefield);

// Win check function
bool gamefield_is_win(struct GameField* gamefield);

#endif