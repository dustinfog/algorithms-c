/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   find_in_rotated.h
 * Author: panzd
 *
 * Created on October 27, 2016, 10:13 AM
 */

#ifndef FIND_IN_ROTATED_H
#define FIND_IN_ROTATED_H

#ifdef __cplusplus
extern "C" {
#endif

    int findRotatedJoint(int array[], int len);
    /**
     * 一个数组是由一个递减数列左移若干位形成的，比如{4，3，2，1，6，5}
     * 是由{6，5，4，3，2，1}左移两位形成的，在这种数组中查找某一个数。i
     * @param array
     * @param len
     * @param joint
     * @param value
     * @return 
     */
    int findInRotated(int array[], int len, int joint, int value);


#ifdef __cplusplus
}
#endif

#endif /* FIND_IN_ROTATED_H */

