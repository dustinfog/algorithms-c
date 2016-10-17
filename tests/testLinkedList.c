/*
 * File:   testLinkedList.c
 * Author: panzd
 *
 * Created on Oct 17, 2016, 7:54:18 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../linked_list.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testAppendLinkedListNode() {
    LinkedList* list = createLinkedList();
    int var1 = 1, var2 = 2;
    appendLinkedListNode(list, &var1);
    CU_ASSERT_EQUAL(list->head->value, &var1);
    appendLinkedListNode(list, &var2);
    CU_ASSERT_EQUAL(list->tail->value, &var2);
    CU_ASSERT_EQUAL(list->length, 2);
    freeLinkedList(list);
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("testLinkedList", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if (//(NULL == CU_add_test(pSuite, "testCreateLinkedList", testCreateLinkedList)) ||
          //  (NULL == CU_add_test(pSuite, "testFreeLinkedList", testFreeLinkedList)) ||
            (NULL == CU_add_test(pSuite, "testAppendLinkedListNode", testAppendLinkedListNode))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
