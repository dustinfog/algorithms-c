/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <math.h>
#include <stdio.h>

#include "print_successive.h"

int findStartNumber(int sum, int count, int *start);

/**
 * 输入一个正数n，输出所有和为n连续正数序列。
 * 例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以输出3个连续序列1-5、4-6和7-8。
 * @param sum
 */
void printSuccessiveWithSum(int sum) {
    int maxCount = sqrt(2 * sum);
    for (int count = 2; count <= maxCount; count++) {
        int start;
        if (findStartNumber(sum, count, &start)) {
            for (int j = 0; j < count; j++) {
                printf("%d,", start + j);
            }
            printf("\n");
        }
    }
}

int findStartNumber(int sum, int count, int *start) {
    int denominator = sum - (count - 1) * count / 2;
    if (denominator % count == 0) {
        *start = denominator / count;
        return 1;
    }

    return 0;
}
