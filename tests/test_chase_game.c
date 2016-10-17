/*
 * File:   test_chase_game.c
 * Author: panzd
 *
 * Created on Oct 17, 2016, 2:43:28 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../chase_game.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

#define PLAYERS 5
void testChase() {
    int m[PLAYERS][PLAYERS];
    int order[] = {2, 1, 0, 3, 4};
    int result[PLAYERS]; 

    m[0][1] = 1;
    m[0][2] = 2;
    m[0][3] = 3;
    m[0][4] = 4;

    m[1][0] = 1;
    m[1][2] = 1;
    m[1][3] = 3;
    m[1][4] = 4;

    m[2][0] = 2;
    m[2][1] = 1;
    m[2][3] = 3;
    m[2][4] = 4;

    m[3][0] = 3;
    m[3][1] = 3;
    m[3][2] = 3;
    m[3][4] = 3;

    m[4][0] = 4;
    m[4][1] = 4;
    m[4][2] = 4;
    m[4][3] = 3;
    
    chase((int **)m, order, result, PLAYERS);
    CU_ASSERT_EQUAL(result[0], 3);
    CU_ASSERT_EQUAL(result[1], 4);
    CU_ASSERT_EQUAL(result[2], 1);
    CU_ASSERT_EQUAL(result[3], 0);
    CU_ASSERT_EQUAL(result[4], 2);
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("test_chase_game", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testChase", testChase))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
