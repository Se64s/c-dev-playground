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
#include <stdlib.h>

/*
** https://leetcode.com/explore/learn/card/fun-with-arrays/521/introduction/3240/
*/

// Private macro --------------------------------------------------------------

#define MOD_NAME        "ex_03"
#define LIST_SIZE(a)    (sizeof(a)/sizeof(a[0]))

// Private typedefs -----------------------------------------------------------

// Private declaration --------------------------------------------------------

static void _sortList(int* nums, int numsSize);

// Given an integer array nums sorted in non-decreasing order, return an 
// array of the squares of each number sorted in non-decreasing order.
int* sortedSquares(int* nums, int numsSize, int* returnSize);

// Private definitions --------------------------------------------------------

// Use bubble sort algorithm
// TODO: Implement quick sort
static void _sortList(int* nums, int numsSize)
{
    if (nums == NULL)
    {
        return;
    }

    for (int i = 0; i < (numsSize - 1); i++)
    {
        for (int j = 0; j < (numsSize - 1 - i); j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int swap_var = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = swap_var;
            }
        }
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize)
{
    int *sqr_list = NULL;

    if (nums == NULL || returnSize == NULL)
    {
        return sqr_list;
    }

    sqr_list = calloc(numsSize, sizeof(int));

    if (sqr_list == NULL)
    {
        return sqr_list;
    }

    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i++)
    {
        sqr_list[i] = nums[i] * nums[i];
    }

    _sortList(sqr_list, numsSize);

    return sqr_list;
}

// Public definitions ---------------------------------------------------------

void module_run(void)
{
    printf("Module: %s\n", MOD_NAME);

    int test_list[] = { -4, -2, 0, 2, 40 };
    int result_list_size = 0;
    int *result_list = sortedSquares(test_list, LIST_SIZE(test_list), &result_list_size);

    if (result_list != NULL && result_list_size > 0)
    {
        for (int i = 0; i < result_list_size; i++)
        {
            printf("Test result: [%d] %d\n", i, result_list[i]);
        }
    }
}

/* EOF */