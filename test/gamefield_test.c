#include <gamefield.h>

#include <ctest.h>

CTEST(gamefield_suite, initialization_deletion)
{
    struct GameField* gamefield = gamefield_init();
    ASSERT_NOT_EQUAL(1, gamefield == NULL);
    gamefield_free(gamefield);
}

CTEST(gamefield_suite, swapping_tiles)
{
    const struct Point UP = {0, 1};
    const struct Point DOWN = {0, -1};
    const struct Point LEFT = {1, 0};
    const struct Point RIGHT = {-1, 0};

    struct GameField* gamefield = gamefield_init();

    ASSERT_EQUAL(true, gamefield_swap(gamefield, DOWN));
    ASSERT_EQUAL(gamefield->blank_tile.x, 3);
    ASSERT_EQUAL(gamefield->blank_tile.y, 2);

    ASSERT_EQUAL(true, gamefield_swap(gamefield, RIGHT));
    ASSERT_EQUAL(gamefield->blank_tile.x, 2);
    ASSERT_EQUAL(gamefield->blank_tile.y, 2);

    ASSERT_EQUAL(true, gamefield_swap(gamefield, LEFT));
    ASSERT_EQUAL(gamefield->blank_tile.x, 3);
    ASSERT_EQUAL(gamefield->blank_tile.y, 2);

    ASSERT_EQUAL(true, gamefield_swap(gamefield, UP));
    ASSERT_EQUAL(gamefield->blank_tile.x, 3);
    ASSERT_EQUAL(gamefield->blank_tile.y, 3);

    ASSERT_EQUAL(false, gamefield_swap(gamefield, UP));

    gamefield_free(gamefield);
}

CTEST(gamefield_suite, shuffling_tiles)
{
    struct GameField* gamefield = gamefield_init();
    struct Point blank = gamefield->blank_tile;

    ASSERT_EQUAL(0, gamefield->field[blank.y][blank.y]);

    gamefield_free(gamefield);
}
