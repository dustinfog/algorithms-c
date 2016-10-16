/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: panzd
 *
 * Created on October 16, 2016, 10:33 AM
 */

#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
/*
 * 
 */
int main(int argc, char** argv) {
    int data[] = {
	1, 2, 0, 3, 4,
	2, 3, 4, 5, 1,
	1, 1, 5, 3, 0		
    };
    matrix m = {data, 5, 3};
    
    int x, y;
    int maxSum = getMaxSumSubMatrix(&m, 2, 2, &x, &y);
    printf("%d, %d : %d", x, y, maxSum);
    
    return (EXIT_SUCCESS);
}

