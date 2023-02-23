#ifndef CW_15PUZZLE_TRPO_SRC_GAMEFIELD_H_
#define CW_15PUZZLE_TRPO_SRC_GAMEFIELD_H_

struct Point {
    int x;
    int y;
};

struct GameField {
    int field[4][4];
    struct Point blank_tile;
};

struct GameField* gamefield_init();
void gamefield_free(struct GameField* gamefield);

void gamefield_print(struct GameField* gamefield);

#endif