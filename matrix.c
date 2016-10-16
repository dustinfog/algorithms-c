/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "matrix.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define getIndex(w, x, y) (y) * (w) + (x)

int getDatum(matrix *m, int x, int y)
{
    return *(m->data + getIndex(m->with, x, y));
}

void setDatum(matrix *m, int x, int y, int v)
{
    *(m->data + getIndex(m->with, x, y)) = v;
}

int virtualSum(matrix *m, int x, int y, int h) {
    int sum = 0;
    for(int vi = 0; vi < h; vi ++) {
	sum += getDatum(m, x, y +vi); 
    }

    return sum;
}

int getMaxSumSubMatrix(matrix *m, int w, int h, int *x, int *y)
{
    int *vSumBuff = malloc(sizeof(int) * m->with * m->height);
    for(int i = 0; i < m->with *m->height; i ++) {
	* (vSumBuff + i) = -1;
    }
    matrix subM = { vSumBuff, w, h };
    int maxSum = 0;

    for(int i = 0; i <= m->with - w; i ++) {
	for (int j = 0; j <= m->height - h; j ++) {
	    int sum = 0;
	    for(int subX = i; subX < i + w; subX ++) {
		int vSum = getDatum(&subM, subX, j);
		if (vSum == -1) {
		    vSum = virtualSum(m, subX, j, h);
		    setDatum(&subM, subX, j, vSum);
		} 

		sum += vSum;
	    }

	    if (sum > maxSum) {
		maxSum = sum;
		*x = i;
		*y = j;
	    }
	}
    }
    
    free(vSumBuff);
    return maxSum;
}
