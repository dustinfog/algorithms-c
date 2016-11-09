#include "find_diverse.h"

int find_one_diverse(int arr[], int length)
{
    int diverse = 0;
    for(int i = 0; i < length; i ++)
    {
	diverse ^= arr[i];
    }

    return diverse;	
}
/**
 * 一个整型数组里除了两个数字之外，其他的数字都出现了两次。
 * 请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
 * @param arr
 * @param length
 * @return 
 */
void find_diverse(int arr[], int length, int *num1, int *num2) {
    int xor_res = 0;
    for (int i = 0; i < length; i++) {
        xor_res ^= arr[i];
    }

    int bit1_pos = 0;
    while ((xor_res & 0x1) == 0) {
        xor_res = xor_res >> 1;
        ++bit1_pos;
    }

    int arr1[length], arr2[length], length1 = 0, length2 = 0;
    
    for (int i = 0; i < length; i ++) {
	if (((arr[i] >> bit1_pos) & 0x1) == 1)	{
	    arr1[length1] = arr[i];
	    length1 ++;
    	} else {
	    arr2[length2] = arr[i];
	    length2 ++; 
	}
    }

    *num1 = find_one_diverse(arr1, length1);
    *num2 = find_one_diverse(arr2, length2);
}
