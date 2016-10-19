/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include "bst.h"
#include "linked_list.h"

binarySearchTreeNode *binarySearchTreeNodeCreate(int value);
void binarySearchTreeNodeFree(binarySearchTreeNode *node);

binarySearchTree *binarySearchTreeCreate() {
    binarySearchTree *tree = malloc(sizeof(binarySearchTree));
    tree->root = 0;
    tree->count = 0;
    return tree;
}

void binarySearchTreeFree(binarySearchTree *tree) {
    binarySearchTreeNodeFree(tree->root);
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
		left = 0;
	    } else {
		itrNode = itrNode->left;
		left = 1;
	    }
	}
	
	node = binarySearchTreeNodeCreate(value);
	if (left) {
	    parent->left = node;
	} else {
	    parent->right = node;
	}
    } else {
	node = binarySearchTreeNodeCreate(value);
	tree->root = node;
    }

    tree->count ++;
    return node;
}

binarySearchTreeNode *binarySearchTreeNodeCreate(int value) {
    binarySearchTreeNode *node = malloc(sizeof(binarySearchTreeNode));
    node->value = value; 
    node->left = NULL;
    node->right = NULL;

    return node;
}

void binarySearchTreeNodeFree(binarySearchTreeNode *node) {
    if (node == NULL) {
	return;
    }
    binarySearchTreeNodeFree(node->left);
    binarySearchTreeNodeFree(node->right);
    
    free(node);
}