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
    void linkedListMerge(linkedList *list, linkedList *another);
    int linkedListShift(linkedList *list);

#ifdef __cplusplus
}
#endif

#endif /* LIST_H */

