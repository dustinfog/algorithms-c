/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
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

void linkedListMerge(linkedList *list, linkedList *another)
{
    if (!another->length) {
	return;
    }
    
    list->tail->next = another->head;
    another->head->prev = list->tail;
    list->tail = another->tail;

    linkedListFree(another, 0);
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