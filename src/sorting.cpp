#include "sorting.h"
#include <vector>

// Sorts the given sequence using in-place insertion sort
void insertion_sort(std::vector<int> &vec) {
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
