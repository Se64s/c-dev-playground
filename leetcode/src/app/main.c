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
#include "module.h"

#include <stdio.h>

/* Private function ---------------------------------------------------------*/

void show_args(int argc, char **argv)
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

/* Public functions ---------------------------------------------------------*/

int main(int argc, char **argv)
{
    show_args(argc, argv);

    module_run();

    return 0;
}

/* EOF */