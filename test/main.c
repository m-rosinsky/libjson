/*!
 * @file test/main.c
 *
 * @brief This file defines tests for the json lib.
 */

#include <stdio.h>

#include "../src/json.h"

int
main (void)
{
    json_t * p_json = json_create("{}");
    if (NULL == p_json)
    {
        printf("create failed\n");
        return 1;
    }

    printf("All tests passed\n");
    return 0;
}

/***   end of file   ***/
