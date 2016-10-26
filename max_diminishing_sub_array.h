/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   max_diminishing_sub_array.h
 * Author: panzd
 *
 * Created on October 26, 2016, 9:29 AM
 */

#ifndef MAX_DIMINISHING_SUB_ARRAY_H
#define MAX_DIMINISHING_SUB_ARRAY_H

#ifdef __cplusplus
extern "C" {
#endif
    /**
     * 求一个数组的最长递减子序列 比如{9，4，3，2，5，4，3，2}的最长递减子序列为{9，5，4，3，2}
     * 
     * @param array
     * @param len
     * @param subArray
     * @return 
     */
    int findMaxDiminishingSubArray(int *array, int len, int **subArray);
#ifdef __cplusplus
}
#endif

#endif /* MAX_DIMINISHING_SUB_ARRAY_H */

