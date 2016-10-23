/*
 * File:   test_arrays.c
 * Author: panzd
 *
 * Created on Oct 23, 2016, 5:49:30 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../arrays.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testSelectionSort() {
    int arr[] = {5, 8, 6, 7, 7, 4};
    int len = 6;
    selectionSort(arr, len);

    CU_ASSERT_EQUAL(arr[0], 4);
    CU_ASSERT_EQUAL(arr[1], 5);
    CU_ASSERT_EQUAL(arr[2], 6);
    CU_ASSERT_EQUAL(arr[3], 7);
    CU_ASSERT_EQUAL(arr[4], 7);
    CU_ASSERT_EQUAL(arr[5], 8);
}

void testInsertSort() {
    int arr[] = {5, 8, 6, 7, 7, 4};
    int len = 6;
    insertSort(arr, len);

    CU_ASSERT_EQUAL(arr[0], 4);
    CU_ASSERT_EQUAL(arr[1], 5);
    CU_ASSERT_EQUAL(arr[2], 6);
    CU_ASSERT_EQUAL(arr[3], 7);
    CU_ASSERT_EQUAL(arr[4], 7);
    CU_ASSERT_EQUAL(arr[5], 8);
}

void testQuickSort() {
    int arr[] = {5, 8, 6, 7, 7, 4};
    int len = 6;
    quickSort(arr, len);

    CU_ASSERT_EQUAL(arr[0], 4);
    CU_ASSERT_EQUAL(arr[1], 5);
    CU_ASSERT_EQUAL(arr[2], 6);
    CU_ASSERT_EQUAL(arr[3], 7);
    CU_ASSERT_EQUAL(arr[4], 7);
    CU_ASSERT_EQUAL(arr[5], 8);
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("test_arrays", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testSelectionSort", testSelectionSort)) ||
            (NULL == CU_add_test(pSuite, "testInsertSort", testInsertSort)) ||
            (NULL == CU_add_test(pSuite, "testQuickSort", testQuickSort))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
