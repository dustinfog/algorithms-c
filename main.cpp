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
#include "find_diverse.h"
#include "linked_list.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    linkedList *sharedList = linkedListCreate();
    linkedListPush(sharedList, 5);
    linkedListPush(sharedList, 6);
    linkedListPush(sharedList, 7);

    
    
    return 0;
}

