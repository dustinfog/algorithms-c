/*
 * File:   newcunittest.c
 * Author: panzd
 *
 * Created on Oct 20, 2016, 7:41:47 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../count_beads.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

#define BEAD_NUM 7

void testCountBeads() {
    int beads[] = {0, 0, 0, 2, 0, 1, 1};
    int beadNum = BEAD_NUM;
    int colorNum = 3;
    int begin = -1;
    int end = -1;
    int result = countBeads(beads, beadNum, colorNum, &begin, &end);
 
    printf("%d %d %d\n", result, begin, end);
    CU_ASSERT_EQUAL(3, result);
    CU_ASSERT_EQUAL(3, begin);
    CU_ASSERT_EQUAL(5, end);
    
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testCountBeads", testCountBeads))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
