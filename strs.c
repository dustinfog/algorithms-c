#include "strs.h"
#include <string.h>


/**
 * 题目：输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，
 * 则删除之后的第一个字符串变成”Thy r stdnts.”。
 * @param str
 * @param str_len
 * @param sequence
 * @param seq_len
 * @param pRemLen
 */
void removeSubSeq(char str[], int strLen, char sequence[], int seqLen, int *pRemLen) {
    char dict[256];
    memset(dict, 0, 256);
    for(int i = 0; i < seqLen; i ++) {
	dict[sequence[i]] = 1;
    }

    int remLen = 0;
    
    for(int i = 0; i < strLen; i ++)
    {
	if (dict[str[i]] == 0) {
	    str[remLen] = str[i];
	    remLen ++;
    	}
    }

    str[remLen] = '\0';
    *pRemLen = remLen;
}
