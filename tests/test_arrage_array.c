/*
 * File:   test_arrage_array.c
 * Author: panzd
 *
 * Created on Nov 1, 2016, 9:34:53 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../arrange_array.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testArrangeArray() {
    int arr[] = {1, 2, 3, 4, 5};
    int len = 5;
    arrangeArray(arr, len);

    int meanStart = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] % 2 == 0) {
            if (!meanStart) {
                meanStart = 1;
            }
        } else if (meanStart == 1) {
            CU_ASSERT(0);
        }
    }
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("test_arrage_array", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testArrangeArray", testArrangeArray))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
