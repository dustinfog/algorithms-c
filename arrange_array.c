/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "arrange_array.h"
#include "arrays.h"

/**
 *输入一个整数数组，调整数组中数字的顺序，使得所有奇数位于数组的前半部分，
 *所有偶数位于数组的后半部分。要求时间复杂度为O(n)。 
 * @param arr
 * @param len
 */
void arrangeArray(int arr[], int len) {
    int begin = 0;
    int end = len - 1;

    while (end > begin) {
        while (arr[begin] % 2 == 1) {
            begin++;
        }

        while (arr[end] % 2 == 0) {
            end--;
        }

        if (end > begin) {
            array_exchange(arr, begin, end);
            begin++;
            end--;
        }
    }
}
