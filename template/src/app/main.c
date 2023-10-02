/**
 * @file main.c
 * @author Sebastián Del Moral
 * @brief Test application
 * @version 0.1
 * @date 2023-09-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "main.h"
#include "test_mod.h"

int main(int argc, char **argv)
{
    test_hello();

    test_show_args(argc, argv);

    return 0;
}

/* EOF */