/**
 * @file    xx_mod.c
 * @author  Sebastián Del Moral
 * @brief   Exercise test source.
 * @version 0.1
 * @date    2023-09-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

// Private macro --------------------------------------------------------------

#define MOD_NAME "ex_00"

// Private typedefs -----------------------------------------------------------

// Private declaration --------------------------------------------------------

int sum(int num1, int num2);

// Private definitions --------------------------------------------------------

int sum(int num1, int num2)
{
    return (num1 + num2);
}

// Public definitions ---------------------------------------------------------

void module_run(void)
{
    printf("Module: %s\n", MOD_NAME);

    int sum1 = 1;
    int sum2 = 2;

    int result = sum(sum1, sum2);

    printf("%d + %d = %d\n", sum1, sum2, result);
}

/* EOF */