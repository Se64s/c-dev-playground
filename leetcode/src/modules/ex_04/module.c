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
** Exercise:
** https://leetcode.com/explore/learn/card/fun-with-arrays/525/inserting-items-into-an-array/3245/
*/

// Private macro --------------------------------------------------------------

#define MOD_NAME            "ex_04"
#define LIST_N_ELEMENT(a)   (sizeof(a)/sizeof(a[0]))

// Private typedefs -----------------------------------------------------------

// Private declaration --------------------------------------------------------

static void insert_value_on_index(int *list, size_t list_size, int value, size_t index);
void duplicateZeros(int* arr, int arrSize);

// Private definitions --------------------------------------------------------

static void insert_value_on_index(int *list, size_t list_size, int value, size_t index)
{
    if ((list == NULL) || (index >= list_size))
    {
        return;
    }

    for (size_t i = list_size - 2; i >= index; i--)
    {
        list[i + 1] = list[i];
    }

    list [index] = value;
}

void duplicateZeros(int* arr, int arrSize)
{
    if ((arr == NULL) || (arrSize == 0))
    {
        return;
    }

    for (size_t i = 0; i < (arrSize - 1); i++)
    {
        if (arr[i] == 0)
        {
            insert_value_on_index(arr, arrSize, 0, i + 1);
            i++;
        }
    }
}

// Public definitions ---------------------------------------------------------

void module_run(void)
{
    printf("Module: %s\n", MOD_NAME);

    int test_list[] = {1,0,2,3,0,4,5,0};

    duplicateZeros(test_list, LIST_N_ELEMENT(test_list));

    for (int i = 0; i < LIST_N_ELEMENT(test_list); i++)
    {
        printf("Test result: [%d] %d\n", i, test_list[i]);
    }
}

/* EOF */