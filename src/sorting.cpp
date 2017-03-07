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

//Sorts the given input using in-place quick sort.
//Should be called as quick_sort(A, 0, A.size())
void quick_sort(std::vector<int> &vec, int lo, int hi){
  if(lo < hi){
    //Partition the input between lo and hi
    int p = partition(vec, lo, hi);
    //Sort the list to the left and to the right of the pivot p
    quick_sort(vec, lo, p);
    quick_sort(vec, p + 1, hi);
  }
}

//Helper function for quick_sort.
//Partitions the input between lo and hi, using lo as pivot
int partition(std::vector<int> &vec, int lo, int hi){
  //We pick the value at lo as pivot
  int pivot = vec[lo];
  //Create two search-heads
  int i = lo - 1;
  int j = hi;
  while(true){
    //If the element at the search-head does not need to move, move the head
    do {
      i++;
    } while(vec[i] < pivot);
    do {
      j--;
    } while(vec[j] > pivot);
    //Our search-heads have collided => We have gone through the entire interval
    if(i >= j){
      return j;
    }
    //Swap the elements at the heads
    int tmp = vec[i];
    vec[i] = vec[j];
    vec[j] = tmp;
  }
}
