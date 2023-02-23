#include <stdio.h>

#include <gamefield.h>

int main()
{
    struct GameField* gamefield = gamefield_init();
    gamefield_print(gamefield);
    gamefield_free(gamefield);
}