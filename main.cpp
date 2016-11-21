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
#include "reverse_stack.h"

using namespace std;

/*
 * 2,3,4,5,6,8,9,12,15,16,18,20,24
 */
int main(int argc, char** argv) {
    linkedList *stack = linkedListCreate();
    linkedListUnshift(stack, 1);
    linkedListUnshift(stack, 2);
    linkedListUnshift(stack, 3);
    linkedListUnshift(stack, 4);
    linkedListUnshift(stack, 5);

    linkedListPrint(stack);
    reverse_stack(stack);
    linkedListPrint(stack);

    
    
    return 0;
}

