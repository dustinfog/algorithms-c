/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   count_beads.h
 * Author: panzd
 *
 * Created on October 20, 2016, 7:09 PM
 */

#ifndef COUNT_BEADS_H
#define COUNT_BEADS_H

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * 一串首尾相连的珠子(m个)，有N种颜色(N<=10)
     * 设计一个算法，取出其中一段，要求包含所有N中颜色，并使长度最短。
     * 并分析时间复杂度与空间复杂度。
     * @param beads
     * @param beadNum
     * @param colorNum
     * @param begin
     * @param end
     * @return 
     */
int countBeads(int beads[], int beadNum, int colorNum, int *begin, int *end);

#ifdef __cplusplus
}
#endif

#endif /* COUNT_BEADS_H */

