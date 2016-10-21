/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   list.h
 * Author: panzd
 *
 * Created on October 17, 2016, 7:32 PM
 */

#ifndef LIST_H
#define LIST_H

#ifdef __cplusplus
extern "C" {
#endif
    typedef struct linkedListNode {
	int value;
	struct linkedListNode *prev;
	struct linkedListNode *next;
    } linkedListNode;
    
    typedef struct linkedList {
	int length;
	linkedListNode *head, *tail;
    } linkedList;

    linkedList *linkedListCreate(void);
    void linkedListFree(linkedList *list, int freeNodes);
    linkedListNode *linkedListPush(linkedList *list, int value);
    int linkedListShift(linkedList *list);
    void linkedListAppend(linkedList *list, linkedList *another);

    /**
     * 两个非降序链表的并集，1->2->3 和 2->3->5 并为 1->2->3->5
     * 另外只能输出结果，不能修改两个链表的数据。
     * @param list
     * @param another
     */
    linkedList *linkedListAppend1(linkedList *list, linkedList *another);

#ifdef __cplusplus
}
#endif

#endif /* LIST_H */

