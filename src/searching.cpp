#include "searching.h"
#include <cmath>
#include <vector>

/*
    Returns the index at which the target is found in the vector, assumes vec to
   be sorted
*/
int binary_search(std::vector<int> &vec, int target) {
  int lower = 0;
  int upper = vec.size() - 1;

  // As long as there exists a subarray, continue search
  while (lower <= upper) {
    int middle = std::floor((lower + upper) / 2);

    if (vec.at(middle) < target) {
      lower = middle + 1;
    } else if (vec.at(middle) > target) {
      upper = middle - 1;
    } else {
      return middle;
    }
  }
  return -1;
}
