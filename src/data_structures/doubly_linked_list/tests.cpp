#include "main.cpp"
#include <gtest/gtest.h>


class TestDoublyLinkedList : public ::testing::Test {
    protected:
        void SetUp() {
            node1 = new CNode();
            node2 = new CNode();
            node3 = new CNode();
            
            node1 -> next = node2;
            node1 -> data = 11;
            
            node2 -> prev = node1;
            node2 -> next = node3;
            node2 -> data = 22;

            node3 -> prev = node2;
            node3 -> data = 33;
        }
        void TearDown() {
            delete node1;
            delete node2;
            delete node3;
        }

        CNode* node1;
        CNode* node2;
        CNode* node3;
};

/* SEARCH FUNCTION TESTS*/
TEST_F(TestDoublyLinkedList, testSearchPassNULLHead) {
    ASSERT_DEATH(search(NULL, 5);, "passed list head is null");
}

TEST_F(TestDoublyLinkedList, testSearchPassNotExistingData) {
    ASSERT_TRUE(search(node1, 55) == NULL);
}

TEST_F(TestDoublyLinkedList, testSearchLookingForNodeIsHead) {
    ASSERT_EQ(search(node1, 11), node1);
}

TEST_F(TestDoublyLinkedList, testSearchLookingForNodeIsTail) {
    ASSERT_EQ(search(node1, 33), node3);
}

TEST_F(TestDoublyLinkedList, testSearchLookingForNodeInMid) {
    ASSERT_EQ(search(node1, 22), node2);
}

/*INSERT AFTER FUNCTION TESTS*/
TEST_F(TestDoublyLinkedList, testInsertAfterNullNode) {
    ASSERT_DEATH(insertAfter(NULL, 5);, "you are trying to add new node after null one");
}

TEST_F(TestDoublyLinkedList, testInsertAfterHead) {
    CNode* inserted = insertAfter(node1, 666);
    ASSERT_EQ(inserted -> data, 666);
    ASSERT_EQ(inserted -> prev, node1);
    ASSERT_EQ(inserted -> next, node2);
}

TEST_F(TestDoublyLinkedList, testInsertAfterTail) {
    CNode* inserted = insertAfter(node3, 666);
    ASSERT_EQ(inserted -> data, 666);
    ASSERT_EQ(inserted -> prev, node3);
    ASSERT_TRUE(inserted -> next == NULL);
}

TEST_F(TestDoublyLinkedList, testInsertAfterNodeInMid) {
    CNode* inserted = insertAfter(node2, 666);
    ASSERT_EQ(inserted -> data, 666);
    ASSERT_EQ(inserted -> prev, node2);
    ASSERT_EQ(inserted -> next, node3);
}

/*INSERT BEFORE FUNCTION TESTS*/
TEST_F(TestDoublyLinkedList, testInsertBeforeNullNode) {
    ASSERT_DEATH(insertBefore(NULL, 5);, "you are trying to add new node before null one");
}

TEST_F(TestDoublyLinkedList, testInsertBeforeHead) {
    CNode* inserted = insertBefore(node1, 777);
    ASSERT_EQ(inserted -> data, 777);
    ASSERT_TRUE(inserted -> prev == NULL);
    ASSERT_EQ(inserted -> next, node1);
}

TEST_F(TestDoublyLinkedList, testInsertBeforeTail) {
    CNode* inserted = insertBefore(node3, 777);
    ASSERT_EQ(inserted -> data, 777);
    ASSERT_TRUE(inserted -> prev == node2);
    ASSERT_EQ(inserted -> next, node3);
}

TEST_F(TestDoublyLinkedList, testInsertBeforeNodeInMid) {
    CNode* inserted = insertBefore(node2, 777);
    ASSERT_EQ(inserted -> data, 777);
    ASSERT_TRUE(inserted -> prev == node1);
    ASSERT_EQ(inserted -> next, node2);
}

/*UNIFY TWO LISTS TESTS*/
TEST_F(TestDoublyLinkedList, testUnifyFirstListIsEmpty) {
    CNode* newHead = unify(NULL, node1);
    ASSERT_EQ(newHead, node1);
}

TEST_F(TestDoublyLinkedList, testUnifySecondListIsEmpty) {
    CNode* newHead = unify(node1, NULL);
    ASSERT_EQ(newHead, node1);
}

TEST_F(TestDoublyLinkedList, testUnifyBothListsAreEmpty) {
    ASSERT_TRUE(unify(NULL, NULL) == NULL);
}

TEST_F(TestDoublyLinkedList, testUnifyLists) {
    CNode* node4 = new CNode();
    CNode* node5 = new CNode();

    node4 -> data = 44;
    node4 -> next = node5;
    node5 -> prev = node4;

    ASSERT_EQ(unify(node4, node1), node4);
    ASSERT_EQ(node5 -> next, node1);
    ASSERT_EQ(node1 -> prev, node5);
}

/*DELETE NODE FUNCTION TESTS*/
TEST(TestDeleteNode, testDeleteNullNode) {
    ASSERT_DEATH(deleteAt(NULL);, "you are trying delete null node");
}

TEST(TestDeleteNode, testDeleteHead) {
    CNode* node1 = new CNode();
    CNode* node2 = new CNode();

    node1 -> next = node2;
    node2 -> prev = node1;

    deleteAt(node1);
    ASSERT_TRUE(node2 -> prev == NULL);

    delete node2;
}

TEST(TestDeleteNode, testDeleteTail) {
    CNode* node1 = new CNode();
    CNode* node2 = new CNode();

    node1 -> next = node2;
    node2 -> prev = node1;

    deleteAt(node2);
    ASSERT_TRUE(node1 -> next == NULL);

    delete node1;
}

TEST(TestDeleteNode, testDeleteNodeInMid) {
    CNode* node1 = new CNode();
    CNode* node2 = new CNode();
    CNode* node3 = new CNode();

    node1 -> next = node2;
    node2 -> prev = node1;
    node2 -> next = node3;
    node3 -> prev = node2;

    deleteAt(node2);
    ASSERT_EQ(node1 -> next, node3);
    ASSERT_EQ(node3 -> prev, node1);

    delete node1;
    delete node3;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
