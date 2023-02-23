#include <gamefield.h>

#include <ctest.h>

CTEST(gamefield_suite, initialization_deletion)
{
    struct GameField* gamefield = gamefield_init();
    ASSERT_NOT_EQUAL(gamefield == NULL, 1);
    gamefield_free(gamefield);
}
