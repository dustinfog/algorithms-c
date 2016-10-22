/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   matrix.h
 * Author: panzd
 *
 * Created on October 16, 2016, 10:34 AM
 */

#ifndef MATRIX_H
#define MATRIX_H

#ifdef __cplusplus
extern "C" {
#endif

#define matrixDatum(m, x, y) *((m)->data + (y) * (m)->width + (x))
    typedef struct matrix {
	int *data;
	int width;
	int height;
    } matrix;

    int matrixGetDatum(matrix *m, int x, int y);
    void matrixSetDatum(matrix *m, int x, int y, int v);
    int maxtrixVirtualSum(matrix *m, int x, int y, int h);
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
    int matrixGetMaxSumSub(matrix *m, int w, int h, int *x, int *y);

     /**
      * 对于一个整数矩阵，存在一种运算，对矩阵中任意元素加一时，需要其相邻（上下左右）
      * 某一个元素也加一，现给出一正数矩阵，判断其是否能够由一个全零矩阵经过上述运算得到。
      */
    int isDeriveFromZero(matrix *m);

#ifdef __cplusplus
}
#endif

#endif /* MATRIX_H */

