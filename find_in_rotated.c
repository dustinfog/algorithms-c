/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "find_in_rotated.h"

int findRotatedJoint(int array[], int len) {
    int from = 0, to = len - 1;
    if (array[from] > array[to]) {
        return 0;
    }

    while (from < to) {
        int median = from + (to - from) / 2;

        if (array[from] < array[median]) {
            to = median;
        } else {
            from = median + 1;
        }
    }

    return from;
}

/**
 * 一个数组是由一个递减数列左移若干位形成的，比如{4，3，2，1，6，5}
 * 是由{6，5，4，3，2，1}左移两位形成的，在这种数组中查找某一个数。
 * @param array
 * @param len
 * @param joint
 * @param value
 * @return 
 */

#define ROTATE_INDEX(vIndex, joint, len) ((vIndex) + (joint)) % (len); 

int findInRotated(int array[], int len, int joint, int value) {
    int vFrom = 0, vTo = len - 1;
    int aFrom = ROTATE_INDEX(vFrom, joint, len);
    int aTo = ROTATE_INDEX(vTo, joint, len);
    while (vFrom < vTo) {
        int vMedian, aMedian;

        if (value > array[aFrom] || value < array[aTo]) {
            return -1;
        }

        vMedian = vFrom + (vTo - vFrom) / 2;
	aMedian = ROTATE_INDEX(vMedian, joint, len);
        if (value > array[aMedian]) {
            vTo = vMedian - 1;
	    aTo = ROTATE_INDEX(vTo, joint, len);
        } else if (value < array[aMedian]) {
            vFrom = vMedian + 1;
	    aFrom = ROTATE_INDEX(vFrom, joint, len);
        } else {
            return aMedian;
        }
    }

    return -1;
}