/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include "linked_list.h"

LinkedList *createLinkedList() {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->length = 0;
    list->head = list->tail = 0;
    return list;
}

void freeLinkedList(LinkedList *list){
    LinkedListNode *node = list->head;
    while(node) {
	LinkedListNode *next = node->next;
	free(node);
	node = next;
    }

    free(list);
}

void appendLinkedListNode(LinkedList *list, void *value) {
    LinkedListNode *node = malloc(sizeof(LinkedListNode));
    node->value = value;

    if (!list->length) {
	list->head = list->tail = node;	
    } else {
    	node->prev = list->tail;
    	list->tail->next = node;
	list->tail = node;
    }

    list->length ++;
}
