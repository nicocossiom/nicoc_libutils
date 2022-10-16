/**
 * Copyright (c) 2022 "Nicolas Cossio Miravalles"
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include <gtest/gtest.h>

#include "linked_list.h"
TEST(TestListEmptyCreation, BasicAssertions) {
    linked_list *list = list_create();
    EXPECT_NE(list, nullptr);
    EXPECT_EQ(list->head, nullptr);
    EXPECT_EQ(list->last, nullptr);
    EXPECT_EQ(list->size, 0);
}
TEST(TestListAppendNullListFail, BasicAssertions) {
    linked_list *list = NULL;
    op_status status = list_append(list, (void *)5);
    EXPECT_EQ(status.success, false);
}
TEST(TestListAppend1Elem, BasicAssertions) {
    linked_list *list = list_create();
    op_status status = list_append(list, (void *)1);
    EXPECT_EQ(status.success, true);
    EXPECT_EQ(status.error_message, nullptr);
    EXPECT_EQ(list->size, 1);
    EXPECT_EQ(list->head->data, (void *)1);
    EXPECT_EQ(list->last->data, (void *)1);
}

TEST(TestListAppend2Elem, BasicAssertions) {
    linked_list *list = list_create();
    op_status status = list_append(list, (void *)1);
    status = list_append(list, (void *)2);
    EXPECT_EQ(list->size, 2);
    EXPECT_EQ(list->head->data, (void *)1);
    EXPECT_EQ(list->last->data, (void *)2);
}

TEST(TestListPrependNullListFail, BasicAssertions) {
    linked_list *list = NULL;
    op_status status = list_prepend(list, (void *)5);
    EXPECT_EQ(status.success, false);
}
TEST(TestListPrepend1Elem, BasicAssertions) {
    linked_list *list = list_create();
    op_status status = list_prepend(list, (void *)1);
    EXPECT_EQ(status.success, true);
    EXPECT_EQ(status.error_message, nullptr);
    EXPECT_EQ(list->size, 1);
    EXPECT_EQ(list->head->data, (void *)1);
    EXPECT_EQ(list->last->data, (void *)1);
}

TEST(TestListPrepend2Elem, BasicAssertions) {
    linked_list *list = list_create();
    op_status status = list_prepend(list, (void *)1);
    status = list_prepend(list, (void *)2);
    EXPECT_EQ(list->size, 2);
    EXPECT_EQ(list->head->data, (void *)2);
    EXPECT_EQ(list->last->data, (void *)1);
}


TEST(TestListReplaceAt, BasicAssertions){
    linked_list *list = list_create();
    op_status status = list_append(list, (void *)1);
    status = list_append(list, (void *)2);
}