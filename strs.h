/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   strings.h
 * Author: panzd
 *
 * Created on November 11, 2016, 9:41 AM
 */

#ifndef STRINGS_H
#define STRINGS_H

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * 题目：输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，
     * 则删除之后的第一个字符串变成”Thy r stdnts.”。
     * @param str
     * @param str_len
     * @param sequence
     * @param seq_len
     * @param pRemLen
     */
    void removeSubSeq(char *str, int str_len, char *sequence, int seq_len, int *pRemLen);


#ifdef __cplusplus
}
#endif

#endif /* STRINGS_H */

