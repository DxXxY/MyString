#include "binary_str.h"

void binary_str::operator=(const char* str)
{
    if (prov(str)) {
        Setstr(str);
    }
}

bool binary_str::prov(const char* str1)
{
    int size = 0;
    bool x = true;
    while (str1[size] != '\0') {
        if (str1[size] != '0' and str1[size] != '1') {
            x = 0;
            break;
        }
        size++;
    }
    return x;
}
