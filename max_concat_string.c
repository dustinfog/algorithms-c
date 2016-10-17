/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdbool.h>
#include <string.h>
#include "max_concat_string.h"

bool isConcatable(char *str1, char *str2, int len) 
{
    return memcmp(str1 + 1, str2, len - 1) == 0;
}