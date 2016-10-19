/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bst.h
 * Author: panzd
 *
 * Created on October 19, 2016, 9:23 AM
 */

#ifndef BST_H
#define BST_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct binarySearchTreeNode {
	int value;
	struct binarySearchTreeNode *left;
	struct binarySearchTreeNode *right;
    } binarySearchTreeNode;
    
    typedef struct binarySearchTree {
	binarySearchTreeNode *root;
	int count;
    } binarySearchTree;

    binarySearchTree *binarySearchTreeCreate();
    void binarySearchTreeFree(binarySearchTree *tree);
    binarySearchTreeNode *binarySearchTreePut(binarySearchTree *tree, int value);


#ifdef __cplusplus
}
#endif

#endif /* BST_H */

