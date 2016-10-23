/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <limits.h>
#include <stdlib.h>
#include <mach/mach_init.h>

#include "arrays.h"

void array_exchange(int arr[], int pos1, int pos2) {
    int value1 = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = value1;
}

void array_shuffle(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        array_exchange(arr, i, rand() % len);
    }
}

void selectionSort(int arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        int min = INT_MAX;
        int minPos = -1;
        for (int j = i; j < len; j++) {
            if (arr[j] < min) {
                min = arr[j];
                minPos = j;
            }
        }

        array_exchange(arr, i, minPos);
    }
}

void insertSort(int arr[], int len) {
    for (int i = 1; i < len; i++) {
        int sample = arr[i];
        for (int j = i; j > 0; j--) {
            if (arr[j - 1] <= sample) {
		break;
            }
	    array_exchange(arr, j, j - 1);
        }
    }
}

void _quickSort(int arr[], int from, int to);

void quickSort(int arr[], int len) {
    array_shuffle(arr, len);

    _quickSort(arr, 0, len - 1);
}

void _quickSort(int arr[], int from, int to) {
    if (to <= from) {
        return;
    }
    int sample = arr[from];

    int equalLength = 1;
    int cursor = from + 1;
    int biggerStart = to;
    while (cursor < biggerStart) {
        int cur = arr[cursor];
        if (cur > sample) {
            array_exchange(arr, cursor, biggerStart);
            biggerStart--;
        } else {
            if (cur < sample) {
                array_exchange(arr, cursor - equalLength, cursor);
            } else {
                equalLength++;
            }
            cursor++;
        }
    }

    _quickSort(arr, from, cursor - equalLength - 1);
    _quickSort(arr, cursor, to);
}