#ifndef SORTING_H
#define SORTING_H
#include <vector>

void insertion_sort(std::vector<int> &vec);
void merge_sort(std::vector<int> &vec);

void quick_sort(std::vector<int> &vec, int lo, int hi);

int partition(std::vector<int> &vec, int lo, int hi);

#endif /* ifndef SORTING_H */
