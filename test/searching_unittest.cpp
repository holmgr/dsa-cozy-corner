#include "searching.h"
#include <limits.h>
#include <vector>
#include "gtest/gtest.h"

// Tests binary_search()

// Tests empty input.
TEST(BinarySearchTest, Empty) {
  std::vector<int> empty_vec;

  EXPECT_EQ(-1, binary_search(empty_vec, 0));
}

// Tests finding existing values.
TEST(BinarySearchTest, Positive) {
  std::vector<int> vec = {3, 4, 15, 17, 18};

  EXPECT_EQ(2, binary_search(vec, 15));
  EXPECT_EQ(4, binary_search(vec, 18));
  EXPECT_EQ(0, binary_search(vec, 3));
}

// Tests output for values not in vector
TEST(BinarySearchTest, Negative) {
  std::vector<int> vec = {3, 4, 15, 17, 18};

  EXPECT_EQ(-1, binary_search(vec, 24));
}
