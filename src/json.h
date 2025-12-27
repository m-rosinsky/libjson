/*!
 * @file src/json.h
 *
 * @brief This file is the root of the library, which is
 *          responsible for JSON parsing.
 */

#ifndef _SRC_JSON_H
#define _SRC_JSON_H

#include <stdlib.h>

/*!
 * @brief This type defines a JSON context.
 *
 *          It is implemented in json.c so as to be opaque.
 */
typedef struct _json json_t;

/*!
 * @brief This function creates a JSON context from a raw string.
 *
 * @param p_str The raw string.
 *
 * @return A parsed JSON context. NULL on error.
 */
json_t *
json_create (const char * p_str);

#endif // _SRC_JSON_H

/***   end of file   ***/
