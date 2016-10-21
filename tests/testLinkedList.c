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

void testLinkedListNodePush() {
    linkedList* list = linkedListCreate();
    linkedListPush(list, 1);
    CU_ASSERT_EQUAL(list->head->value, 1);
    linkedListPush(list, 2);
    CU_ASSERT_EQUAL(list->tail->value, 2);
    CU_ASSERT_EQUAL(list->length, 2);
    int value = linkedListShift(list);
    CU_ASSERT_EQUAL(value, 1);
    CU_ASSERT_EQUAL(list->length, 1); 
    linkedListFree(list, 1);
}

void testLinkedListAppend1() {
    linkedList* list = linkedListCreate();
    linkedListPush(list, 1); 
    linkedListPush(list, 2); 
    linkedListPush(list, 2); 
    linkedListPush(list, 3); 

    linkedList* another = linkedListCreate();
    linkedListPush(list, 2); 
    linkedListPush(list, 3); 
    linkedListPush(list, 4); 

    linkedList *merged = linkedListAppend1(list, another);
    if (merged)
    {
	int value = linkedListShift(merged);
	CU_ASSERT_EQUAL(1, value);
	value = linkedListShift(merged);
	CU_ASSERT_EQUAL(2, value);
	value = linkedListShift(merged);
	CU_ASSERT_EQUAL(2, value);
	value = linkedListShift(merged);
	CU_ASSERT_EQUAL(3, value);
	value = linkedListShift(merged);
	CU_ASSERT_EQUAL(4, value);
	
	linkedListFree(merged, 1);
    }

    linkedListFree(list, 1);
    linkedListFree(another, 1);
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
            (NULL == CU_add_test(pSuite, "testAppendLinkedListNode", testLinkedListNodePush))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
