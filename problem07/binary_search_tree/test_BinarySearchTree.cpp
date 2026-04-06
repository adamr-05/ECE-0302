#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "BinarySearchTree.hpp"

/* Provided test cases */

TEST_CASE("BST: Test Insert", "[insert]") {
    BinarySearchTree<int, int> bst1;

    REQUIRE(bst1.isEmpty());

    bst1.insert(10, 10);
    REQUIRE_FALSE(bst1.isEmpty());
}

TEST_CASE("BST: Test Duplicate Insert", "[duplicate insert]") {
    BinarySearchTree<int, int> bst1;
    
    REQUIRE(bst1.insert(12, 12));
    REQUIRE(!bst1.insert(12, 12));
}

TEST_CASE("BST: Test Remove With No Children", "[remove]") {
    BinarySearchTree<int, int> bst1;

    bst1.insert(10, 10);
    bst1.insert(5, 5);
    bst1.insert(15, 15);

    int item;

    REQUIRE(bst1.retrieve(10, item));
    REQUIRE(bst1.retrieve(5, item));
    REQUIRE(bst1.retrieve(15, item));

    bst1.remove(5);
    REQUIRE_FALSE(bst1.retrieve(5, item));

    bst1.remove(15);
    REQUIRE_FALSE(bst1.retrieve(15, item));

    bst1.remove(10);
    REQUIRE_FALSE(bst1.retrieve(10, item));

    REQUIRE(bst1.isEmpty());
}

TEST_CASE("BST: Test Copy Assign", "[copy assign]") {
    BinarySearchTree<int, int> bst1;

    bst1.insert(50, 50);
    bst1.insert(0, 0);
    bst1.insert(100, 100);
    bst1.insert(25, 25);
    bst1.insert(75, 75);

    BinarySearchTree<int, int> bst2;

    bst2 = bst1;

    bst1.destroy();

    REQUIRE(bst1.isEmpty());

    REQUIRE_FALSE(bst2.isEmpty());

    int item;
    REQUIRE(bst2.retrieve(100, item));
    REQUIRE(bst2.retrieve(75, item));
    REQUIRE(bst2.retrieve(50, item));
    REQUIRE(bst2.retrieve(25, item));
    REQUIRE_FALSE(bst2.retrieve(51, item));
}

/* Your test cases here */

TEST_CASE("BST: Insert into empty tree", "[insert]") {
    BinarySearchTree<int, int> bst;
    REQUIRE(bst.isEmpty());
    REQUIRE(bst.insert(10, 10));
    REQUIRE_FALSE(bst.isEmpty());
    int item;
    REQUIRE(bst.retrieve(10, item));
    REQUIRE(item == 10);
}

TEST_CASE("BST: Insert duplicate", "[insert]") {
    BinarySearchTree<int, int> bst;
    REQUIRE(bst.insert(5, 5));
    REQUIRE_FALSE(bst.insert(5, 5));
}

TEST_CASE("BST: Insert ascending order", "[insert]") {
    BinarySearchTree<int, int> bst;
    for (int i = 1; i <= 5; i++)
        REQUIRE(bst.insert(i, i));
    int item;
    for (int i = 1; i <= 5; i++)
        REQUIRE(bst.retrieve(i, item));
}

TEST_CASE("BST: Insert descending order", "[insert]") {
    BinarySearchTree<int, int> bst;
    for (int i = 5; i >= 1; i--)
        REQUIRE(bst.insert(i, i));
    int item;
    for (int i = 1; i <= 5; i++)
        REQUIRE(bst.retrieve(i, item));
}

TEST_CASE("BST: Remove from empty tree", "[remove]") {
    BinarySearchTree<int, int> bst;
    REQUIRE_FALSE(bst.remove(5));
}

TEST_CASE("BST: Remove nonexistent key", "[remove]") {
    BinarySearchTree<int, int> bst;
    bst.insert(10, 10);
    REQUIRE_FALSE(bst.remove(99));
}

TEST_CASE("BST: Remove single node (root leaf)", "[remove]") {
    BinarySearchTree<int, int> bst;
    bst.insert(10, 10);
    REQUIRE(bst.remove(10));
    REQUIRE(bst.isEmpty());
}

TEST_CASE("BST: Remove leaf node", "[remove]") {
    BinarySearchTree<int, int> bst;
    bst.insert(10, 10);
    bst.insert(5, 5);
    bst.insert(15, 15);
    REQUIRE(bst.remove(5));
    int item;
    REQUIRE_FALSE(bst.retrieve(5, item));
    REQUIRE(bst.retrieve(10, item));
    REQUIRE(bst.retrieve(15, item));
}

TEST_CASE("BST: Remove node with only right child", "[remove]") {
    BinarySearchTree<int, int> bst;
    bst.insert(10, 10);
    bst.insert(5, 5);
    bst.insert(7, 7);
    REQUIRE(bst.remove(5));
    int item;
    REQUIRE_FALSE(bst.retrieve(5, item));
    REQUIRE(bst.retrieve(7, item));
    REQUIRE(bst.retrieve(10, item));
}

TEST_CASE("BST: Remove node with only left child", "[remove]") {
    BinarySearchTree<int, int> bst;
    bst.insert(10, 10);
    bst.insert(5, 5);
    bst.insert(3, 3);
    REQUIRE(bst.remove(5));
    int item;
    REQUIRE_FALSE(bst.retrieve(5, item));
    REQUIRE(bst.retrieve(3, item));
    REQUIRE(bst.retrieve(10, item));
}

TEST_CASE("BST: Remove node with two children", "[remove]") {
    BinarySearchTree<int, int> bst;
    bst.insert(10, 10);
    bst.insert(5, 5);
    bst.insert(15, 15);
    bst.insert(3, 3);
    bst.insert(7, 7);
    REQUIRE(bst.remove(5));
    int item;
    REQUIRE_FALSE(bst.retrieve(5, item));
    REQUIRE(bst.retrieve(3, item));
    REQUIRE(bst.retrieve(7, item));
    REQUIRE(bst.retrieve(10, item));
    REQUIRE(bst.retrieve(15, item));
}

TEST_CASE("BST: Remove root with two children", "[remove]") {
    BinarySearchTree<int, int> bst;
    bst.insert(10, 10);
    bst.insert(5, 5);
    bst.insert(15, 15);
    REQUIRE(bst.remove(10));
    int item;
    REQUIRE_FALSE(bst.retrieve(10, item));
    REQUIRE(bst.retrieve(5, item));
    REQUIRE(bst.retrieve(15, item));
}

TEST_CASE("BST: Remove all nodes", "[remove]") {
    BinarySearchTree<int, int> bst;
    bst.insert(10, 10);
    bst.insert(5, 5);
    bst.insert(15, 15);
    bst.insert(3, 3);
    bst.insert(7, 7);
    REQUIRE(bst.remove(3));
    REQUIRE(bst.remove(7));
    REQUIRE(bst.remove(5));
    REQUIRE(bst.remove(15));
    REQUIRE(bst.remove(10));
    REQUIRE(bst.isEmpty());
}

TEST_CASE("BST: Copy constructor", "[copy]") {
    BinarySearchTree<int, int> bst1;
    bst1.insert(10, 10);
    bst1.insert(5, 5);
    bst1.insert(15, 15);

    BinarySearchTree<int, int> bst2(bst1);
    bst1.destroy();
    REQUIRE(bst1.isEmpty());
    REQUIRE_FALSE(bst2.isEmpty());

    int item;
    REQUIRE(bst2.retrieve(10, item));
    REQUIRE(bst2.retrieve(5, item));
    REQUIRE(bst2.retrieve(15, item));
}

TEST_CASE("BST: TreeSort", "[treesort]") {
    BinarySearchTree<int, int> bst;
    int arr[] = {8, 3, 1, 6, 4, 7, 10, 14, 13};
    bst.treeSort(arr, 9);
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[1] == 3);
    REQUIRE(arr[2] == 4);
    REQUIRE(arr[3] == 6);
    REQUIRE(arr[4] == 7);
    REQUIRE(arr[5] == 8);
    REQUIRE(arr[6] == 10);
    REQUIRE(arr[7] == 13);
    REQUIRE(arr[8] == 14);
}

TEST_CASE("BST: TreeSort duplicates throw", "[treesort]") {
    BinarySearchTree<int, int> bst;
    int arr[] = {5, 3, 5};
    REQUIRE_THROWS(bst.treeSort(arr, 3));
}