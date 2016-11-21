#include "reverse_stack.h"

   /**
    * 用递归颠倒一个栈。例如输入栈{1, 2, 3, 4, 5}，1在栈顶。
    * 颠倒之后的栈为{5, 4, 3, 2, 1}，5处在栈顶。
    * @param stack
    */
void reverse_stack(linkedList *stack){
    if (stack->length <= 1) {
	return;
    }
    
    int top = linkedListShift(stack);
    reverse_stack(stack);
    int bottom = linkedListShift(stack);
    reverse_stack(stack);
    linkedListUnshift(stack, top);
    reverse_stack(stack);
    linkedListUnshift(stack, bottom);
}
