/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include <string.h>
#include "matrix.h"

int matrixGetDatum(matrix *m, int x, int y) {
    return matrixDatum(m, x, y);
}

void matrixSetDatum(matrix *m, int x, int y, int v) {
    matrixDatum(m, x, y) = v;
}

int maxtrixVirtualSum(matrix *m, int x, int y, int h) {
    int sum = 0;
    for (int vi = 0; vi < h; vi++) {
        sum += matrixGetDatum(m, x, y + vi);
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
int matrixGetMaxSumSub(matrix *m, int w, int h, int *x, int *y) {
    int *vSumBuff = malloc(sizeof (int) * m->width * m->height);
    for (int i = 0; i < m->width * m->height; i++) {
        * (vSumBuff + i) = -1;
    }
    matrix subM = {vSumBuff, w, h};
    int maxSum = 0;

    for (int i = 0; i <= m->width - w; i++) {
        for (int j = 0; j <= m->height - h; j++) {
            int sum = 0;
            for (int subX = i; subX < i + w; subX++) {
                int vSum = matrixGetDatum(&subM, subX, j);
                if (vSum == -1) {
                    vSum = maxtrixVirtualSum(m, subX, j, h);
                    matrixSetDatum(&subM, subX, j, vSum);
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

int isDeriveFromZero(matrix *m) {
    for (int y = 0; y < m->height; y++) {
        for (int x = 0; x < m->width; x++) {
            int datumXY = matrixDatum(m, x, y);
            int datumXYR, datumXYD;

            if (datumXY == 0) {
                continue;
            }

            if (x < m->width - 1) {
                datumXYR = matrixDatum(m, x + 1, y);
                if (datumXYR > datumXY) {
                    datumXY = 0;
                    matrixDatum(m, x + 1, y) = datumXYR - datumXY;
                } else {
                    datumXY = datumXY - datumXYR;
                    matrixDatum(m, x + 1, y) = 0;
                }
            }

            if (datumXY == 0) {
                continue;
            }

            if (y == m->height - 1) {
                return 0;
            }

            datumXYD = matrixDatum(m, x, y + 1);

            if (datumXY > datumXYD) {
                return 0;
            }

            datumXY = 0;
            matrixDatum(m, x, y + 1) = datumXYD - datumXY;
        }
    }
    return 1;
}