/*
 * File:   test_bst.c
 * Author: panzd
 *
 * Created on Oct 19, 2016, 2:22:46 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../bst.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testBinarySearchTree() {
    binarySearchTree* tree = binarySearchTreeCreate();
    
    binarySearchTreeNode *node18 = binarySearchTreePut(tree, 18);
    CU_ASSERT_EQUAL(tree->root, node18)
    
    binarySearchTreeNode *node6 = binarySearchTreePut(tree, 6);
    CU_ASSERT_EQUAL(node6, node18->left)
    binarySearchTreeNode *node4 = binarySearchTreePut(tree, 4);
    CU_ASSERT_EQUAL(node4, node6->left)
    binarySearchTreeNode *node8 = binarySearchTreePut(tree, 8);
    CU_ASSERT_EQUAL(node8, node6->right);
    binarySearchTreePut(tree, 14);
    binarySearchTreePut(tree, 12);
    binarySearchTreePut(tree, 16);
   
    CU_ASSERT_EQUAL(tree->count, 7); 
    binarySearchTreeFree(tree);
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("test_bst", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testBinarySearchTreeFree", testBinarySearchTree))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
