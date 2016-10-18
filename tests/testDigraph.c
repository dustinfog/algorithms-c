/*
 * File:   testDigraph.c
 * Author: panzd
 *
 * Created on Oct 18, 2016, 4:39:06 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../digraph.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testHasEdge() {
    Digraph* digraph = createDigraph();
    DigraphNode *node;
    for(int i = 0; i < 5; i ++)
    {
	int next = i == 4 ? -1 : i + 1; 
	node = createDigraphNode(&next, 1);
	digraph = appendDigraphNode(digraph, node);
    }
    
    int longest = findLongestPath(digraph);
    CU_ASSERT_EQUAL(4, longest);
   
    int nexts[] = {0, 2};
    node = createDigraphNode(nexts, 2);
    digraph = appendDigraphNode(digraph, node); 
    longest = findLongestPath(digraph);
    
    CU_ASSERT_EQUAL(5, longest);

    freeDigraph(digraph);

}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("testDigraph", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testHasEdge", testHasEdge))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
