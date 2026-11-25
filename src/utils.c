#include "utils.h"

#include <ctype.h>
#include <string.h>

int isint(const char *str)
{
    for (size_t i = 0; i < strlen(str); i++)
    {
        if (isdigit(str[i]) == 0)
        {
            return 0;
        }
    }

    return 1;
}