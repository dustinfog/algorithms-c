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
