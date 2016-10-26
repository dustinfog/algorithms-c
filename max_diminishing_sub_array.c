/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <stdlib.h>
#include <malloc/malloc.h>

#include "max_diminishing_sub_array.h"

typedef struct seqNode {
    int prevIndex;
    int len;
} seqNode;

/**
 * 求一个数组的最长递减子序列 比如{9，4，3，2，5，4，3，2}的最长递减子序列为{9，5，4，3，2}
 * 
 * @param array
 * @param len
 * @param subArray
 * @return 
 */
int findMaxDiminishingSubArray(int *array, int len, int **subArray) {
    seqNode *nodes = NULL;
    int maxLen = 0, index = 0;

    if (len == 0) {
        return 0;
    }

    int trunkSize = sizeof (seqNode) * len;
    nodes = malloc(trunkSize);

    for (int i = 0; i < len; i++) {
        int value = *(array + i);
        seqNode *node = nodes + i;
        
	int j = i - 1;
        while (j >= 0 && *(array + j) < value) j--;
        
        node->prevIndex = j;
        if (j == -1) {
            node->len = 1;
        } else {
	    node->len = (nodes + j)->len + 1;
	}

	if (node->len > maxLen) {
	    maxLen = node->len;
	    index = i;
        }
    }

    *subArray = malloc(sizeof(int) * maxLen);
    for(int i = maxLen - 1; i >= 0; i --)
    {
	*(*subArray + i) = *(array + index);
        index = (nodes + index)->prevIndex;	
    }

    free(nodes);
    return maxLen;
}
