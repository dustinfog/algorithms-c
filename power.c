/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <math.h>
#include "power.h"

int doubleEq(double n1, double n2) {
    double diff = n1 - n2;
    return diff >= -0.00000001 && diff <= 0.00000001;
}

/**
 * 实现函数double Power(double base,int exponent)，求base的exponent次方。
 * @param n
 * @param p
 * @return 
 */
double power(double n, int p) {
    int neg;
    if (doubleEq(n, 0)) {
        if (p <= 0) {
            return NAN;
        }

        return 0;
    }

    if (p == 0) {
	return 1;
    }

    if (p < 0) {
        neg = 1;
        p = -p;
    }

    int ret = n;
    for(int i = 0; i < p; i ++) {
	n *= n;
    }

    if (neg) {
	ret = 1 / ret;
    }

    return ret;
}