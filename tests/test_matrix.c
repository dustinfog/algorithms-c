/*
 * File:   test_matrix.c
 * Author: panzd
 *
 * Created on Oct 17, 2016, 3:03:46 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../matrix.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testGetMaxSumSubMatrix() {

   int data[] = {
	1, 2, 0, 3, 4,
	2, 3, 4, 5, 1,
	1, 1, 5, 3, 0		
    };
    
    matrix m = {data, 5, 3};
    
    int x, y;
    int maxSum = matrixGetMaxSumSub(&m, 2, 2, &x, &y);

    CU_ASSERT_EQUAL(x, 2);
    CU_ASSERT_EQUAL(y, 1);
    CU_ASSERT_EQUAL(maxSum, 17);
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("test_matrix", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testGetMaxSumSubMatrix", testGetMaxSumSubMatrix))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
