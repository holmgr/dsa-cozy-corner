#include "sorting.h"
#include <limits.h>
#include <vector>
#include "gtest/gtest.h"

// Tests insertion_sort()

// Tests empty input.
TEST(InsertionSortTest, Empty) {
  std::vector<int> empty_vec;

  insertion_sort(empty_vec);
  EXPECT_TRUE(empty_vec.empty());
}

// Tests non empty positive input.
TEST(InsertionSortTest, Positive) {
  std::vector<int> vec = {3, 4, 17, 18, 15};
  std::vector<int> vec_sorted = {3, 4, 15, 17, 18};

  insertion_sort(vec);
  for (int i = 0; i < vec.size(); i++) {
    EXPECT_EQ(vec_sorted[i], vec[i]);
  }
}

// Tests mixed input.
TEST(InsertionSortTest, Mixed) {
  std::vector<int> vec = {-3, 4, -17, 18, 15};
  std::vector<int> vec_sorted = {-17, -3, 4, 15, 18};

  insertion_sort(vec);
  for (int i = 0; i < vec.size(); i++) {
    EXPECT_EQ(vec_sorted[i], vec[i]);
  }
}

// Tests quick_sort()

// Tests empty input.
TEST(QuickSortTest, Empty) {
  std::vector<int> empty_vec;

  quick_sort(empty_vec, 0, empty_vec.size());
  EXPECT_TRUE(empty_vec.empty());
}

// Tests non empty positive input.
TEST(QuickSortTest, Positive) {
  std::vector<int> vec = {3, 4, 17, 18, 15};
  std::vector<int> vec_sorted = {3, 4, 15, 17, 18};

  quick_sort(vec, 0, vec.size());
  for (int i = 0; i < vec.size(); i++) {
    EXPECT_EQ(vec_sorted[i], vec[i]);
  }
}

// Tests mixed input.
TEST(QuickSortTest, Mixed) {
  std::vector<int> vec = {-3, 4, -17, 18, 15};
  std::vector<int> vec_sorted = {-17, -3, 4, 15, 18};

  quick_sort(vec, 0, vec.size());
  for (int i = 0; i < vec.size(); i++) {
    EXPECT_EQ(vec_sorted[i], vec[i]);
  }
}
