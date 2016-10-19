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

    typedef struct matrix {
	int *data;
	int with;
	int height;
    } matrix;

    int matrixGetDatum(matrix *m, int x, int y);
    void matrixSetDatum(matrix *m, int x, int y, int v);
    int maxtrixVirtualSum(matrix *m, int x, int y, int h);
    int matrixGetMaxSumSub(matrix *m, int w, int h, int *x, int *y);

#ifdef __cplusplus
}
#endif

#endif /* MATRIX_H */

