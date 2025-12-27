/*!
 * @file src/json.c
 *
 * @brief This file is the root of the library, which is
 *          responsible for JSON parsing.
 */

#include "json.h"

/*!
 * @brief This type defines a JSON context.
 */
struct _json
{
    
};

json_t *
json_create (const char * p_str)
{
    int status = -1;
    json_t * p_json = calloc(1, sizeof(json_t));
    if (NULL == p_json)
    {
        goto EXIT;
    }

    EXIT:
        if (-1 == status)
        {
            json_destroy(p_json);
            p_json = NULL;
        }
        return p_json;
}

/***   end of file   ***/
