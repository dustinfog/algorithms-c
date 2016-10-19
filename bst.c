/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include "bst.h"
#include "linked_list.h"

binarySearchTreeNode *createBinarySearchTreeNode(int value);

binarySearchTree *binarySearchTreeCreate() {
    binarySearchTree *tree = malloc(sizeof(binarySearchTree));
    tree->root = 0;
    tree->count = 0;
    return tree;
}

void binarySearchTreeFree(binarySearchTree *tree) {
    free(tree);
}

binarySearchTreeNode *binarySearchTreePut(binarySearchTree *tree, int value) {
    binarySearchTreeNode *node = NULL;
    if (tree->root) {
	binarySearchTreeNode *itrNode = tree->root;
	binarySearchTreeNode *parent = NULL;
	int left = 0;	
	while(itrNode) {
	    if (value == itrNode->value) {
		return 0;
	    }
	    
	    parent = itrNode;
	    if (value > itrNode->value) {
		itrNode = itrNode->right;
		left = 1;
	    } else {
		itrNode = itrNode->left;
		left = 0;
	    }
	}
	
	node = createBinarySearchTreeNode(value);
	if (left) {
	    parent->left = node;
	} else {
	    parent->right = node;
	}
	
    } else {
	node = createBinarySearchTreeNode(value);
	tree->root = node;
    }

    tree->count ++;
    return node;
}

binarySearchTreeNode *createBinarySearchTreeNode(int value) {
    binarySearchTreeNode *node = malloc(sizeof(binarySearchTreeNode));
    node->value = value; 

    return node;
}

void freeBinarySearchTreeNode(binarySearchTreeNode *node) {
    linkedList *list = linkedListCreate()
    if (node->left) {
	freeBinarySearchTreeNode(node->left);
    } else if(node->right) {
	freeBinarySearchTreeNode(node->right);
    }
    free(node);
}