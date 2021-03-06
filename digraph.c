/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "digraph.h"
 void seekPath(digraph *graph, int index, int *maxLen, int *paths, int *checked);

digraphNode *digraphNodeCreate(int *nextIndices, int numNexts)
{
    digraphNode *node = malloc(sizeof(digraphNode) + sizeof(int) * numNexts);
    node->numNexts = numNexts;
    memcpy(node->nextIndices, nextIndices, numNexts * sizeof(int) / sizeof(char));
    return node;
}

digraph *digraphCreate()
{
    digraph *digraph = malloc(sizeof(digraph));
    digraph->numNodes = 0;
     
    return digraph;
 }

digraph *digraphAdd(digraph *graph, digraphNode *node)
{
   graph = realloc(graph, sizeof(graph) + sizeof(void *) * ( graph->numNodes + 1));  
   graph->nodes[graph->numNodes] = node; 
   graph->numNodes ++;

   return graph;
}

 void freeDigraph(digraph *digraph)
 {
     for(int i = 0; i < digraph->numNodes; i ++)
     {
	 free(digraph->nodes[i]);
     }
     free(digraph);
 }

 int findLongestPath(digraph *digraph)
 {
     int numPaths = digraph->numNodes * digraph->numNodes;
     int *paths = malloc(sizeof(void *) * numPaths);
     int *checked = malloc(sizeof(void *) * digraph->numNodes);
     for(int i = 0; i < numPaths; i ++)
     {
	 *(paths + i) = 0;
     }

     for(int i = 0; i < digraph->numNodes; i ++)
     {
	 *(checked + i) = 0;
     }

     int maxLen = 0;

     for(int i = 0; i < digraph->numNodes; i ++)
     {
	 seekPath(digraph, i, &maxLen, paths, checked);
     }

     free(checked);
     free(paths);
    return maxLen;
 }

 
#define DIGRAPH_PATH(digraph, paths, from, to) *((paths) + (to) * (digraph)->numNodes + (from))
 void seekPath(digraph *graph, int index, int *maxLen, int *paths, int *checked)
 {
     digraphNode *node = *(graph->nodes + index);
     if(*(checked + index)) {
	 return;
     }
     
     *(checked + index) = 1;

     if (node->numNexts == 0) {
	 return;
     }
     
     for(int i = 0; i < node->numNexts; i ++)
     {
	 int nextIndex = node->nextIndices[i];
	 if (nextIndex < 0 || nextIndex >= graph->numNodes) {
	     continue;
	 }
	 
	 DIGRAPH_PATH(graph, paths, index, nextIndex)= 1;
	 
	 seekPath(graph, nextIndex, maxLen, paths, checked);

	 for(int j = 0; j < graph->numNodes; j ++) {
	     int len = 1 + DIGRAPH_PATH(graph, paths, nextIndex, j);
	     DIGRAPH_PATH(graph, paths, index, j) = len;
	     
	     if (*maxLen < len) {
		 *maxLen = len;
	     }
	 }
     }
 }