/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "arrange_chars.h"
#include "arrays.h"

int permutate(int arr[], int len);

/**
 * 输入一个字符串，打印出该字符串中字符的所有排列。
 * 例如输入字符串abc，则输出由字符a、b、c所能排列出来的所有字符串
 * abc、acb、bac、bca、cab和cba。
 */
void arrangeChars(char *chars){
    int len = strlen(chars);
    int *arr = malloc(sizeof(int) * len);
    
    for (int i = 0; i < len; i ++) {
	arr[i] = i;
    }
    
    while (permutate(arr, len)) {
	for(int i = 0; i < len; i ++) {
	    printf("%c", chars[arr[i]]);
    	}

        printf("\n");
    }
}

int permutate(int arr[], int len) {
    int j = -1, k = -1;
    int p, q;
    for(int i = len - 2; i >= 0; i --) {
	if (arr[i] < arr[i + 1]) {
	    j = i;
	    break;
	}
    }

    if (j == -1) {
	return 0;
    }

    for(int i = len - 1; i > j; i--) {
	if (arr[i] > arr[j]) {
	    k = i;
	    break;
	}
    }

    array_exchange(arr, j, k);
    p = j + 1;
    q = len - 1;
    while(p < q) {
	array_exchange(arr, p, q);
	p ++;
	q --;
    }

    return 1;
}
