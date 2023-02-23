#include <gamefield.h>

#include <stdio.h>
#include <stdlib.h>

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
        printf("-------------\n");
        for (int j = 0; j < 4; j++) {
            putchar('|');
            printf("%d", gamefield->field[i][j]);
            if (gamefield->field[i][j] < 10) {
                putchar(' ');
            }
        }
        putchar('|');
        putchar('\n');
    }
    printf("-------------\n");
}