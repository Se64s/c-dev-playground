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

#define MOD_NAME        "ex_02"
#define LIST_SIZE(a)    (sizeof(a)/sizeof(a[0]))

// Private typedefs -----------------------------------------------------------

// Private declaration --------------------------------------------------------

static int _get_number_digits(int nums);

// Given an array nums of integers, return how many of them contain an even number of digits.
int findNumbers(int* nums, int numsSize);

// Private definitions --------------------------------------------------------

static inline int _get_number_digits(int nums)
{
    int num_digits = 1;
    int pow_value = 10;

    while (pow_value <= nums)
    {
        pow_value *= 10;
        num_digits++;
    }
    
    return num_digits;
}

int findNumbers(int* nums, int numsSize)
{
    int even_cnt = 0;

    if (nums == NULL)
    {
        return even_cnt;
    }

    for (int i = 0; i < numsSize; i++)
    {
        if (!(_get_number_digits(nums[i]) & 0x01))
        {
            even_cnt++;
        }
    }

    return even_cnt;
}

// Public definitions ---------------------------------------------------------

void module_run(void)
{
    printf("Module: %s\n", MOD_NAME);

    int test_list[] = { 100000 };

    int result = findNumbers(test_list, LIST_SIZE(test_list));

    printf("Test result: %d\n", result);
}

/* EOF */