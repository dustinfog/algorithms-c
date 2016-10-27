/*
 * File:   test_find_in_rotated.c
 * Author: panzd
 *
 * Created on Oct 27, 2016, 10:29:25 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../find_in_rotated.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testFindRotatedJoint() {
    int array[] = {4,3,2,1,6,5};
    int len = 6;
    int result = findRotatedJoint(array, len);
    CU_ASSERT_EQUAL(4, result);
}

void testFindInRotated() {
    int array[] = {4,3,2,1,8,7};
    int len = 6;
    int joint = 4;
    int value = 2;
    int result = findInRotated(array, len, joint, value);
    CU_ASSERT_EQUAL(result, 2);
    value = 5;
    result = findInRotated(array, len, joint, value);
    CU_ASSERT_EQUAL(result, -1);
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("test_find_in_rotated", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testFindRotatedJoint", testFindRotatedJoint)) ||
            (NULL == CU_add_test(pSuite, "testFindInRotated", testFindInRotated))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
