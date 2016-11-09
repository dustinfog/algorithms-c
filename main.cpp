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

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int nums[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 6};
    int num1, num2;
    find_diverse(nums, 10, &num1, &num2);
    printf("%d, %d", num1, num2);
    return 0;
}

