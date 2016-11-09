/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   find_diverse.h
 * Author: panzd
 *
 * Created on November 9, 2016, 9:35 AM
 */

#ifndef FIND_DIVERSE_H
#define FIND_DIVERSE_H

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * 一个整型数组里除了两个数字之外，其他的数字都出现了两次。
     * 请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
     * @param arr
     * @param length
     * @return 
     */
    void find_diverse(int arr[], int length, int *num1, int *num2);

#ifdef __cplusplus
}
#endif

#endif /* FIND_DIVERSE_H */

