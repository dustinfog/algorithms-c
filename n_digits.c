#include <string.h>
#include <stdio.h>
#include "n_digits.h"

void print_number(char *number, int length, int maxLength);
int print_next_number(char *number, int *length, int maxLength);
/**
 * 输入数字n，按顺序输出从1最大的n位10进制数。比如输入3，
 * 则输出1、2、3一直到最大的3位数即999。
 * @param n
 */
void print_n_digits(int n)
{
    char digits[n];
    memset(digits, 0, n);
    
    int length = 1;
    while(print_next_number(digits, &length, n));
}

int print_next_number(char *digits, int *length, int maxLength) {
    int carry = 1;
    for(int i = maxLength - 1; i >= maxLength - *length; i --)
    {
        if(digits[i] < 9) {
            digits[i] += carry;
            carry = 0;
            break;
        }

        digits[i] = 0;
    }
    
    if (carry == 0) {
        print_number(digits, *length, maxLength);
        return 1;
    }
    
    if(*length < maxLength) {
	++ (*length); 
        digits[maxLength - *length]  = 1;
	print_number(digits, *length, maxLength);
        return 1;
    }
    
    return 0;
}

void print_number(char *digits, int length, int maxLength)
{
    for (int i = maxLength - length; i < maxLength; i ++) {
        printf("%d", digits[i]);
    }
    
    printf("\n");
}