/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   heap.h
 * Author: panzd
 *
 * Created on October 28, 2016, 9:10 AM
 */

#ifndef HEAP_H
#define HEAP_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct heap {
	int capacity;
	int (*compare)(int a, int b);
	int used;
	int data[];
    } heap;

    heap *heapNew(int capacity, int (*compare)(int a, int b));
    void heapFree(heap *h);
    int heapPut(heap *h, int value);
    int heapPop(heap *h, int *value);
    int maxCallback(int a , int b);
    int minCallback(int a, int b);
    

#ifdef __cplusplus
}
#endif

#endif /* HEAP_H */

