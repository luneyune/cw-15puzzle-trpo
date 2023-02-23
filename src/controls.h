#ifndef CW_15PUZZLE_TRPO_SRC_CONTROLS_H_
#define CW_15PUZZLE_TRPO_SRC_CONTROLS_H_

#define UP_CHAR 'w'
#define LEFT_CHAR 'a'
#define RIGHT_CHAR 'd'
#define DOWN_CHAR 's'

#define QUIT_CHAR 'q'

enum Key {
    UP_k,
    LEFT_k,
    RIGHT_k,
    DOWN_k,
    QUIT_k,
    ERR_k,
};

// Functions for initialization and deinitialization of lib curses
void controls_setup();
void controls_end();

// Functions for getting user input
enum Key controls_user_input();

#endif