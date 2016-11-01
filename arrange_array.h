/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arrange_array.h
 * Author: panzd
 *
 * Created on November 1, 2016, 9:19 AM
 */

#ifndef ARRANGE_ARRAY_H
#define ARRANGE_ARRAY_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 *输入一个整数数组，调整数组中数字的顺序，使得所有奇数位于数组的前半部分，
 *所有偶数位于数组的后半部分。要求时间复杂度为O(n)。 
 * @param arr
 * @param len
 */
void arrangeArray(int arr[], int len);


#ifdef __cplusplus
}
#endif

#endif /* ARRANGE_ARRAY_H */

