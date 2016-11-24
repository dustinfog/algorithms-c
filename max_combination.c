/**
 * 输入一个正整数数组，将它们连接起来排成一个数，输出能排出的所有数字中最小的一个。
 * 例如输入数组{32, 321, 3211}，则输出这两个能排成的最小数字32132。
 * 请给出解决问题的算法，并证明该算法。
 * @param src
 * @param length
 * @return 
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "max_combination.h"
#include "arrays.h"


number *createNumber(const char *buf) {
    unsigned long len = strlen(buf);
    number *num = (number *)malloc(sizeof(number) + len + 1);
    num->len = len;
    strcpy(num->buf, buf);

    return num;
}

void numberExchange(number **arr, int pos1, int pos2) {
    if (pos1 == pos2) {
        return;
    }

    number *value1 = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = value1;
}

int compare(number *n1, number *n2)
{
    int i = 0, j = 0;
    while(n1->buf[i] == n2->buf[j] && i++ < n1->len && j++ < n2->len);
    
    if ( i < n1->len && j < n2->len) {
	return n1->buf[i] - n2->buf[j];
    } else if (i == n1->len && j < n2->len) {
	return n1->buf[0] - n2->buf[j];
    } else if (i < n1->len && j == n2->len) {
	return n1->buf[i] - n2->buf[0];
    } else {
	return 0;
    }
}

void numberSort(number **arr, int from, int to) {
    if (to <= from) {
        return;
    }
    number *sample = arr[from];

    int equalLength = 1;
    int cursor = from + 1;
    int biggerStart = to;
    while (cursor < biggerStart) {
        number *cur = arr[cursor];
        if (compare(cur, sample) > 0) {
            biggerStart--;
            numberExchange(arr, cursor, biggerStart);
        } else {
            if (compare(cur, sample) < 0) {
                numberExchange(arr, cursor - equalLength, cursor);
            } else {
                equalLength++;
            }
            cursor++;
        }
    }

    numberSort(arr, from, cursor - equalLength);
    numberSort(arr, biggerStart, to);
}

void findMaxCombination(number **num, int length) {
    numberSort(num, 0, length);
}


void printNumbers(number **num, int length) {
    for (int i = 0; i < length; i ++)
    {
	printf("%s", num[i]->buf);		
    }
    printf("\n");
}