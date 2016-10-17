/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "chase_game.h"
#include <stdio.h>

/**
 * 谷歌笔试：
 * n支队伍比赛，分别编号为0，1，2。。。。n-1，已知它们之间的实力对比关系，
 * 存储在一个二维数组w[n][n]中，w[i][j] 的值代表编号为i，j的队伍中更强的一支。
 *
 * 所以w[i][j]=i 或者j，现在给出它们的出场顺序，并存储在数组order[n]中，
 * 比如order[n] = {4,3,5,8,1......}，那么第一轮比赛就是 4对3， 5对8。.......
 * 胜者晋级，败者淘汰，同一轮淘汰的所有队伍排名不再细分，即可以随便排，
 * 下一轮由上一轮的胜者按照顺序，再依次两两比，比如可能是4对5,直至出现第一名
 *
 * 编程实现，给出二维数组w，一维数组order 和 用于输出比赛名次的数组result[n]，
 * 求出result。
 * @param m
 * @param order
 * @param result
 * @param n
 */
void chase(int **m, int *order, int *result, int n) {
    int rank = n - 1;
    while( rank > 0){
	int maxPlayerIndex = rank;
	int orderIndex = 0;
	for(int i = 0; i <= maxPlayerIndex / 2; i ++) {
	    int *pplayer1 = order + i * 2;
	    if (i * 2 < maxPlayerIndex) {
		int *pplayer2 = pplayer1 + 1;
	    	int winner = *((int *)m + (*pplayer1) * n + *pplayer2);	
		int loser = winner == *pplayer1 ? *pplayer2 : *pplayer1;
	    	*(result + rank) = loser;
		rank --;
		
		if (maxPlayerIndex == 1) {
		    *result = winner;
		} else {
		    *(order + orderIndex) = winner;
		    orderIndex ++;
		}
	    } else {
		*(order + orderIndex) = *pplayer1;
		orderIndex ++;
	    }
	}	
    }
}