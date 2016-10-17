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
    typedef struct LinkedListNode {
	void *value;
	struct LinkedListNode *prev;
	struct LinkedListNode *next;
    } LinkedListNode;
    
    typedef struct LinkedList {
	int length;
	LinkedListNode *head, *tail;
    } LinkedList;

    LinkedList *createLinkedList();
    void freeLinkedList(LinkedList *list);
    void appendLinkedListNode(LinkedList *list, void *value);

#ifdef __cplusplus
}
#endif

#endif /* LIST_H */

