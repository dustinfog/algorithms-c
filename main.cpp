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
#include "linked_list.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    linkedList *list = linkedListCreate();
    linkedListPush(list, 1);
    linkedListPush(list, 2);
    linkedListPush(list, 3);
    
    printSingleListReversely(list);
    linkedListFree(list, 2);
    return 0;
}

