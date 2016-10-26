/*
 * File:   test_max_diminishing.c
 * Author: panzd
 *
 * Created on Oct 26, 2016, 10:51:28 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../max_diminishing_sub_array.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testFindMaxDiminishingSubArray() {
    int array[] = {9,4,3,2,5,4,3,2};
    int expect[] = {9, 5, 4, 3, 2};
    int len = 8;
    int* subArray = 0;
    int result = findMaxDiminishingSubArray(array, len, &subArray);

    CU_ASSERT_EQUAL(5, result);
    for(int i = 0; i < result; i ++) {
	CU_ASSERT_EQUAL(expect[i], *(subArray + i));	
    }
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("test_max_diminishing", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testFindMaxDiminishingSubArray", testFindMaxDiminishingSubArray))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
