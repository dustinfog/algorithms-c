/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sort.h
 * Author: panzd
 *
 * Created on October 23, 2016, 5:05 PM
 */

#ifndef SORT_H
#define SORT_H

#ifdef __cplusplus
extern "C" {
#endif

    void array_exchange(int arr[], int pos1, int pos2);
    void array_shuffle(int arr[], int len);
    void selectionSort(int arr[], int len);
    void insertSort(int arr[], int len);
    void quickSort(int arr[], int len);

#ifdef __cplusplus
}
#endif

#endif /* SORT_H */

