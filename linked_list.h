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
    linkedListNode *linkedListUnshift(linkedList *list, int value);
    void linkedListAppend(linkedList *list, linkedList *another);
    void linkedListPrint(linkedList *list);

    /**
     * 两个单向链表，找出它们的第一个公共结点。
     * 
     * @param list1
     * @param list2
     * @return 
     */
    linkedListNode *findFirstSharedNode(linkedList *list1, linkedList *list2);
    /**
     * 两个非降序链表的并集，1->2->3 和 2->3->5 并为 1->2->3->5
     * 另外只能输出结果，不能修改两个链表的数据。
     * @param list
     * @param another
     */
    linkedList *linkedListAppend1(linkedList *list, linkedList *another);
    /**
     * 从尾到头输出链表。
     * 题目：输入一个链表的头结点，从尾到头反过来输出每个结点的值。链表结点定义如下：
     */
    void printSingleListReversely(linkedList *list);

#ifdef __cplusplus
}
#endif

#endif /* LIST_H */

