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
** https://leetcode.com/explore/learn/card/fun-with-arrays/525/inserting-items-into-an-array/3253/
*/

// Private macro --------------------------------------------------------------

#define MOD_NAME            "ex_05"
#define LIST_N_ELEMENT(a)   (sizeof(a)/sizeof(a[0]))

// Private typedefs -----------------------------------------------------------

// Private declaration --------------------------------------------------------

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);

// Private definitions --------------------------------------------------------

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    if ((nums1 == NULL) || (nums2 == NULL) || (nums1Size < (m + n)) || (n == 0))
    {
        return;
    }

    if (m == 0)
    {
        for (int i = 0; i < n; i++)
        {
            nums1[i] = nums2[i];
        }

        return;
    }

    for (int i = (m + n) - 1; i >= 0; i--)
    {
        int i_num1 = m - 1;
        int i_num2 = n - 1;

        if ((m > 0) && (n > 0))
        {
            if (nums1[i_num1] > nums2[i_num2])
            {
                nums1[i] = nums1[i_num1];
                m--;
            }
            else
            {
                nums1[i] = nums2[i_num2];
                n--;
            }
        }
        else if (m == 0)
        {
            nums1[i] = nums2[i_num2];
            n--;
        }
        else if (n == 0)
        {
            nums1[i] = nums1[i_num1];
            m--;
        }
    }
}

// Public definitions ---------------------------------------------------------

void module_run(void)
{
    printf("Module: %s\n", MOD_NAME);

    int nums1[] = {2,0};
    int m = 1;
    int nums2[] = {1};
    int n = 1;

    merge(nums1, LIST_N_ELEMENT(nums1), m, nums2, LIST_N_ELEMENT(nums2), n);

    for (int i = 0; i < LIST_N_ELEMENT(nums1); i++)
    {
        printf("Test result: [%d] %d\n", i, nums1[i]);
    }
}

/* EOF */