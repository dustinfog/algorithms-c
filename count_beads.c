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

int countBeads(int beads[], int beadNum, int colorNum, int *begin, int *end) {
    int trunkSize = sizeof (int) * colorNum;
    int *colorCounts = malloc(trunkSize);
    memset(colorCounts, 0, trunkSize);

    int colorCount = 0;
    int minLength = beadNum;
    *begin = *end = 0;
    int front = -1, back = -1;
    do {
        int *p;
        while (colorCount < colorNum) {
            back = (back + 1) % beadNum;
            p = colorCounts + beads[back];

            if (*p == 0) {
                colorCount++;
            }

            (*p)++;
        }

        while (colorCount == colorNum && front < beadNum) {
            front++;
            p = colorCounts + beads[front];
            (*p)--;

            if (*p == 0) {
                int length = beadNum * (back <= front) + back - front + 1;

                if (length < minLength) {
                    minLength = length;

                    *begin = front;
                    *end = back;
                }

                colorCount--;
            }
        }
    } while (front < beadNum);

    free(colorCounts);
    return minLength;
}