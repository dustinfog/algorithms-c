/*
 * File:   test heap.c
 * Author: panzd
 *
 * Created on Oct 28, 2016, 10:14:38 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../heap.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testHeapNew() {
    int capacity = 5;
    heap* h = heapNew(capacity, maxCallback);
    heapPut(h, 5);
    heapPut(h, 8);
    heapPut(h, 4);
    heapPut(h, 3);
    heapPut(h, 7);
    CU_ASSERT_EQUAL(h->used, 5);

    int v;
    heapPop(h, &v); 
    CU_ASSERT_EQUAL(8, v);
    heapPop(h, &v); 
    CU_ASSERT_EQUAL(7, v);
    heapPop(h, &v); 
    CU_ASSERT_EQUAL(5, v);
    heapPop(h, &v); 
    CU_ASSERT_EQUAL(4, v);
    heapPop(h, &v); 
    CU_ASSERT_EQUAL(3, v);
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("test heap", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testHeapNew", testHeapNew))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
