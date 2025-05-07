#include <gtest/gtest.h>
#include <vector>

std::vector<int> BubbleSort(std::vector<int>);
std::vector<int> SmallestSort(std::vector<int>);
std::vector<int> InsertionSort(std::vector<int>);
std::vector<int> MS(std::vector<int>);

TEST(SortingTests, BubbleSortTest) {
    EXPECT_EQ(BubbleSort({ 5, 3, 8, 1 }), std::vector<int>({ 1, 3, 5, 8 }));
    EXPECT_EQ(BubbleSort({ 4, 4, 4 }), std::vector<int>({ 4, 4, 4 }));
    EXPECT_EQ(BubbleSort({}), std::vector<int>({}));
    EXPECT_EQ(BubbleSort({ 1 }), std::vector<int>({ 1 }));
    EXPECT_EQ(BubbleSort({ 10, 9, 8, 7 }), std::vector<int>({ 7, 8, 9, 10 }));
}

TEST(SortingTests, SmallestSortTest) {
    EXPECT_EQ(SmallestSort({ 5, 3, 8, 1 }), std::vector<int>({ 1, 3, 5, 8 }));
    EXPECT_EQ(SmallestSort({ 4, 4, 4 }), std::vector<int>({ 4, 4, 4 }));
    EXPECT_EQ(SmallestSort({}), std::vector<int>({}));
    EXPECT_EQ(SmallestSort({ 1 }), std::vector<int>({ 1 }));
    EXPECT_EQ(SmallestSort({ 10, 9, 8, 7 }), std::vector<int>({ 7, 8, 9, 10 }));
}

TEST(SortingTests, InsertionSortTest) {
    EXPECT_EQ(InsertionSort({ 5, 3, 8, 1 }), std::vector<int>({ 1, 3, 5, 8 }));
    EXPECT_EQ(InsertionSort({ 4, 4, 4 }), std::vector<int>({ 4, 4, 4 }));
    EXPECT_EQ(InsertionSort({}), std::vector<int>({}));
    EXPECT_EQ(InsertionSort({ 1 }), std::vector<int>({ 1 }));
    EXPECT_EQ(InsertionSort({ 10, 9, 8, 7 }), std::vector<int>({ 7, 8, 9, 10 }));
}

TEST(SortingTests, MergeSortTest) {
    EXPECT_EQ(MS({ 5, 3, 8, 1 }), std::vector<int>({ 1, 3, 5, 8 }));
    EXPECT_EQ(MS({ 4, 4, 4 }), std::vector<int>({ 4, 4, 4 }));
    EXPECT_EQ(MS({}), std::vector<int>({}));
    EXPECT_EQ(MS({ 1 }), std::vector<int>({ 1 }));
    EXPECT_EQ(MS({ 10, 9, 8, 7 }), std::vector<int>({ 7, 8, 9, 10 }));
}