/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   reverse_stack.h
 * Author: panzd
 *
 * Created on November 18, 2016, 9:37 AM
 */

#ifndef REVERSE_STACK_H
#define REVERSE_STACK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "linked_list.h"

   /**
    * 用递归颠倒一个栈。例如输入栈{1, 2, 3, 4, 5}，1在栈顶。
    * 颠倒之后的栈为{5, 4, 3, 2, 1}，5处在栈顶。
    * @param stack
    */
void reverse_stack(linkedList *stack);

#ifdef __cplusplus
}
#endif

#endif /* REVERSE_STACK_H */

