/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   max_combination.h
 * Author: panzd
 *
 * Created on November 24, 2016, 9:49 AM
 */

#ifndef MAX_COMBINATION_H
#define MAX_COMBINATION_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct number {
	int len;
	char buf[];
    } number;
    /**
     * 输入一个正整数数组，将它们连接起来排成一个数，输出能排出的所有数字中最小的一个。
     * 例如输入数组{32, 321}，则输出这两个能排成的最小数字32132。
     * 请给出解决问题的算法，并证明该算法。
     * @param src
     * @param subLen
     * @param length
     * @return 
     */
    void findMaxCombination(number **num, int length);
    void printNumbers(number **num, int length);
    number *createNumber(const char *buf);

#ifdef __cplusplus
}
#endif

#endif /* MAX_COMBINATION_H */

