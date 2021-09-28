#pragma once
#include "MyString.h"
class binary_str :
    public MyString
{
public:
    binary_str() {
        Setstr("");
    }
    binary_str(const char* str1){
        if (prov(str1)) {
            Setstr(str1);
        }
        else{
            size = 0;
        }
    }
    void operator=(const char* str);
    bool prov(const char* str1);
    binary_str(binary_str& mystring) {
        Setstr(mystring.str);
    }
};

