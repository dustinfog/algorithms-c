/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#include "bst.h"

linkedList *linkedListCreate(void) {
    linkedList *list = malloc(sizeof(linkedList));
    list->length = 0;
    list->head = list->tail = 0;
    return list;
}

void linkedListFree(linkedList *list, int freeNodes){
    if (freeNodes) {
    	linkedListNode *node = list->head;
    	while(node) {
	    linkedListNode *next = node->next;
	    if (next) {
	    	next->prev = NULL;
	    }
	    free(node);
	    node = next;
        }
    }

    free(list);
}

linkedListNode *linkedListPush(linkedList *list, int value) {
    linkedListNode *node = malloc(sizeof(linkedListNode));
    node->value = value;

    if (!list->length) {
	list->head = list->tail = node;	
	node->prev = node->next = NULL;
    } else {
    	node->prev = list->tail;
	node->next = NULL;
    	list->tail->next = node;
	list->tail = node;
    }

    list->length ++;

    return node;
}

int linkedListShift(linkedList *list)
{
    if (!list->length) {
	return 0;
    }

    linkedListNode *node = list->head;
    int value = node->value;
    
    list->head = node->next;
    if (list->head) {
    	list->head->prev = NULL;
    }
    
    list->length --;

    free(node);

    return value;
}

void linkedListAppend(linkedList *list, linkedList *another)
{
    if (!another->length) {
	return;
    }
    
    list->tail->next = another->head;
    another->head->prev = list->tail;
    list->tail = another->tail;

    linkedListFree(another, 0);
}

linkedList *linkedListAppend1(linkedList *list, linkedList *another)
{
    linkedListNode *n1 = list->head;
    linkedListNode *n2 = another->head;
    
    int h2 = n2->value;
    linkedListNode *cd = NULL;
    
    while(n1 && n1->value != n2->value) {
	n1 = n1->next;
    }

    cd = n1;
    while(n1 && n2 && n1->value == n2->value) {
	n1 = n1->next;
	n2 = n2->next;
    }

    while (n1 && n2 && cd->value == h2 && n1->value != n2->value) {
	cd = cd->next;
	n1 = n1->next;
    }
    
    while(n1 && n2 && n1->value == n2->value) {
	n1 = n1->next;
	n2 = n2->next;
    }
    
    linkedList *merged = NULL;
    if (!n1) {
	merged = linkedListCreate();
	
	n1 = list->head;
	while(n1 != cd) {
	    linkedListPush(merged, n1->value);
	    n1 = n1->next;
	}

	n2 = another->head;
	while(n2) {
	    linkedListPush(merged, n2->value);
	    n2 = n2->next;
	}
    }

    return merged;
}

void printSingleListNodeReversely(linkedListNode *node)
{
    if (!node) {
	return;	
    }
    printSingleListNodeReversely(node->next);
    printf("->%d", node->value);
}
/**
 * 从尾到头输出链表。
 * 题目：输入一个链表的头结点，从尾到头反过来输出每个结点的值。链表结点定义如下：
 */
void printSingleListReversely(linkedList *list)
{
    linkedListNode *node = list->head;
    printf("list");
    printSingleListNodeReversely(node);
}

linkedListNode *findTail(linkedList *list) {
    linkedListNode *node = list->head;
    while(node->next) {
	node = node->next;
    }
    
    return node;
}

    /**
     * 两个单向链表，找出它们的第一个公共结点。
     * 
     * @param list1
     * @param list2
     * @return 
     */
 linkedListNode *findFirstSharedNode(linkedList *list1, linkedList *list2)
 {
     int length1 = list1->length;
     int length2 = list2->length;
     int sharedLength = length1 >length2 ? length2 :length1;
     int start1 = length1 - sharedLength;
     int start2 = length2 - sharedLength;
     linkedListNode *node1 = list1->head;
     linkedListNode *node2 = list2->head;
     while(start1 != 0) {
	 node1 = node1->next;
         start1 --;
     }

     while(start2 != 0) {
	 node2 = node2->next;
         start2 --;
     }
     
     while(node1 != node2) {
	 node1 = node1->next;
     	node2 = node2->next;
     }
     
     return node1;
 }