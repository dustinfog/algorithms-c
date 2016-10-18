/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   digraph.h
 * Author: panzd
 *
 * Created on October 18, 2016, 9:45 AM
 */

#ifndef DIGRAPH_H
#define DIGRAPH_H

#include "linked_list.h"


#ifdef __cplusplus
extern "C" {
#endif

#define DIGRAPH_EDGE(digraph, from, to) *((digraph)->edges + (to) * (digraph)->numVertices + (from))

    typedef struct DigraphNode {
	int value;
	int numNexts;
	int nextIndices[];
    } DigraphNode;
    
    typedef struct Digraph {
	int numNodes;
	DigraphNode *nodes[];
    } Digraph;

    DigraphNode *createDigraphNode(int *nextIndices, int numNexts);
    Digraph  *appendDigraphNode(Digraph *graph, DigraphNode *node);
    Digraph *createDigraph();
    void freeDigraph(Digraph *digraph);
    int findLongestPath(Digraph *digraph);

#ifdef __cplusplus
}
#endif

#endif /* DIGRAPH_H */

