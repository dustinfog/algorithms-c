/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: panzd
 *
 * Created on November 4, 2016, 9:48 AM
 */

#include <cstdlib>
#include <iostream>
#include "strs.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char str[] = "hello, world";
    char seq[] = "eol";
    int remLen = -1;
    removeSubSeq(str, strlen(str), seq, strlen(seq), &remLen);
    
    if (remLen != -1) {
	printf("%s", str);
    }
    
    return 0;
}

