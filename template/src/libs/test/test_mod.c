/**
 * @file test_mod.c
 * @author Sebastián Del Moral
 * @brief Test module source.
 * @version 0.1
 * @date 2023-09-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

void test_hello(void)
{
    printf("Hello world!\n");
}

void test_show_args(int argc, char **argv)
{
    do
    {
        if (argv == NULL)
        {
            printf("argv NULL!\n");
            break;
        }

        for (int i_arg = 0; i_arg < argc; i_arg++)
        {
            if (argv[i_arg] == NULL)
            {
                printf("argv[%d] NULL!\n", i_arg);
                break;
            }
            else
            {
                printf("Arg %d : %s\n", i_arg, argv[i_arg]);
            }
        }

    } while (0);
}

/* EOF */