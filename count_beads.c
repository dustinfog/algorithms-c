/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include <stdio.h>
#include "count_beads.h"


int countBeads(int beads[], int beadNum, int colorNum, int *begin, int *end)
{
    int *colorCounts = malloc(sizeof(int) * colorNum);
    for (int i = 0; i < colorNum; i ++)
    {
	*(colorCounts + i) = 0;
    }
    
    int colorCount = 0;
    for (int i = 0; i < beadNum; i ++)
    {
	int *p = colorCounts + beads[i];
	if (*p == 0) {
	    colorCount += 2;
	}

	*p += 2;
    }

    for (int i = 0; i < colorNum; i ++)
    {
	printf("====%d\n", *(colorCounts + i));
    }

    *begin = -1;
    *end = -1;
    int front = 0, back = beadNum - 1;
    while(*begin == -1 || *end == -1)
    {
	int *p = colorCounts + beads[front];
	if (*begin == -1 && *p - 1 > 0) {
	   front ++;
	   *p -= 1;
	} else {
	   *begin = front;
	}
	
	p = colorCounts + beads[back];
	if (*end == -1 && *p - 1 > 0) {
	    back --;
	    *p -= 1;
	} else {
	    *end = back;
	}
    }

    free(colorCounts);

    if (*begin < *end) {
	return *end - *begin + 1;
    } else {
	return beadNum - *begin + *end + 1;
    }
}
