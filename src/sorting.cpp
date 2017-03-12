#include "sorting.h"
#include <algorithm>
#include <iostream>
#include <vector>

// Sorts the given sequence using in-place insertion sort
void insertion_sort(std::vector<int>& vec) {
  for (int j = 1; j < vec.size(); j++) {
    int key = vec[j];

    // Insert vec[j] into the sorted sequence vec[1, j-1]
    int i = j - 1;
    while (i >= 0 && vec[i] > key) {
      vec[i + 1] = vec[i];
      i = i - 1;
    }
    vec[i + 1] = key;
  }
}

// Sorts the given input using in-place quick sort.
// Should be called as quick_sort(A, 0, A.size())
void quick_sort(std::vector<int>& vec, int lo, int hi) {
  if (lo < hi) {
    // Partition the input between lo and hi
    int p = partition(vec, lo, hi);
    // Sort the list to the left and to the right of the pivot p
    quick_sort(vec, lo, p);
    quick_sort(vec, p + 1, hi);
  }
}

// Helper function for quick_sort.
// Partitions the input between lo and hi, using lo as pivot
int partition(std::vector<int>& vec, int lo, int hi) {
  // We pick the value at lo as pivot
  int pivot = vec[lo];
  // Create two search-heads
  int i = lo - 1;
  int j = hi;
  while (true) {
    // If the element at the search-head does not need to move, move the head
    do {
      i++;
    } while (vec[i] < pivot);
    do {
      j--;
    } while (vec[j] > pivot);
    // Our search-heads have collided => We have gone through the entire
    // interval
    if (i >= j) {
      return j;
    }
    // Swap the elements at the heads
    int tmp = vec[i];
    vec[i] = vec[j];
    vec[j] = tmp;
  }
}

/**
  * Merges the left and right sublists into vec in order
  * Helper function for merge_sort.
**/
void merge(std::vector<int>& vec, std::vector<int>& left,
           std::vector<int>& right) {
  // Pick smallest element of left and right repeatedly and insert into vec
  int i, j, k;
  for (i = 0, j = 0, k = 0; i < left.size() && j < right.size(); k++) {
    if (left[i] <= right[j]) {
      vec[k] = left[i++];
    } else {
      vec[k] = right[j++];
    }
  }

  // Left or right may have values left, consume them
  std::copy(left.begin() + i, left.end(), vec.begin() + k);
  std::copy(right.begin() + j, right.end(), vec.begin() + k);
}

/**
 * Sorts the given sequence using merge sort.
 * Time-complexity:    O(n log n)
 * Space-complexity:   O(n)
 **/
void merge_sort(std::vector<int>& vec) {
  // A list of one or zero elements is sorted by definition
  if (vec.size() <= 1) return;

  // Divide vec into equal-sized sublists
  auto middle = vec.begin() + vec.size() / 2;
  std::vector<int> left(vec.begin(), middle);
  std::vector<int> right(middle, vec.end());

  // Recursively sort both sublists
  merge_sort(left);
  merge_sort(right);

  // Merge the results
  merge(vec, left, right);
}

/**
 * Sorts the given sequence using counting sort.
 * Will sort the given sequence in linear time however all elements must be
 * within the range 0-k inclusive.
 * Time-complexity:    O(n)
 * Space-complexity:   O(k)
 **/
std::vector<int> counting_sort(std::vector<int>& vec, int k) {
  std::vector<int> count(k + 1);
  std::vector<int> result(vec.size());

  // Set count[i] to contain the number of elements of i
  for (int i = 0; i < vec.size(); ++i) {
    count[vec[i]] += 1;
  }

  // Set count[i] to contain the number of elements smaller than i
  int total = 0;
  for (int i = 0; i <= k; ++i) {
    int old_count = count[i];
    count[i] = total;
    total += old_count;
  }

  // Copy values to result, preserving order of inputs with equal values
  for (int i = 0; i < vec.size(); ++i) {
    result[count[vec[i]]] = vec[i];
    count[vec[i]] += 1;
  }

  return result;
}
