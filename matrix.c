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

/**
 * 求一个矩阵中最大的二维矩阵(元素和最大).如:
 * 1 2 0 3 4
 * 2 3 4 5 1
 * 1 1 5 3 0
 * 中最大的是:
 * 4 5
 * 5 3
 * 要求:(1)写出算法;(2)分析时间复杂度;(3)用C写出关键代码
 * @param m
 * @param w
 * @param h
 * @param x
 * @param y
 * @return 
 */
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
