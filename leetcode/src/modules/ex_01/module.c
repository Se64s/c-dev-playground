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
#include <stdbool.h>

// Private macro --------------------------------------------------------------

#define MOD_NAME        "ex_01"
#define LIST_SIZE(a)    (sizeof(a)/sizeof(a[0]))

// Private typedefs -----------------------------------------------------------

// Private declaration --------------------------------------------------------

int findMaxConsecutiveOnes(int* nums, int numsSize);

// Private definitions --------------------------------------------------------

int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int max_cnt_ones = 0;

    if (nums == NULL)
    {
        return max_cnt_ones;
    }

    int cnt_ones = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1)
        {
            cnt_ones++;
        }
        else
        {
            cnt_ones = 0;
        }

        if (cnt_ones > max_cnt_ones)
        {
            max_cnt_ones = cnt_ones;
        }
    }

    return max_cnt_ones;
}

// Public definitions ---------------------------------------------------------

void module_run(void)
{
    printf("Module: %s\n", MOD_NAME);

    int test_list[] = { 1, 1, 0, 1, 1, 1 , 0, 1, 1 };

    int result = findMaxConsecutiveOnes(test_list, LIST_SIZE(test_list));

    printf("Test result: %d\n", result);
}

/* EOF */