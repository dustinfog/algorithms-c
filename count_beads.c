/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "count_beads.h"

void tryUpdateMinLength(int beadNum, int front, int back, int *minLength, int *begin, int *end);

int countBeads(int beads[], int beadNum, int colorNum, int *begin, int *end) {
    int trunkSize = sizeof (int) * colorNum;
    int *colorCounts = malloc(trunkSize);
    memset(colorCounts, 0, trunkSize);

    int colorCount = 0;
    int minLength = beadNum;
    int front = 0, back = 0;
    int follow = 0;
    while (front < beadNum) {
        int *p;
        if (!follow) {
            p = colorCounts + beads[back];

            if (*p == 0) {
                colorCount++;
                if (colorCount == colorNum) {
		    tryUpdateMinLength(beadNum, front, back, &minLength, begin, end);
                    follow = 1;
                }
            }

            (*p) ++;

            back = (back + 1) % beadNum;
        } else {
            p = colorCounts + beads[front];
            (*p) --;

            if (*p == 0) {
                colorCount--;
		tryUpdateMinLength(beadNum, front, back, &minLength, begin, end);
                follow = 0;
            }

            front++;
        }
    }

    free(colorCounts);
    return minLength;
}

void tryUpdateMinLength(int beadNum, int front, int back, int *minLength, int *begin, int *end) {
    int length = beadNum * (back > front) + back - front + 1;

    if (length < *minLength) {
        *minLength = length;

        *begin = front;
        *end = back;
    }
}