#ifndef SORTING_H
#define SORTING_H
#include <vector>

void insertion_sort(std::vector<int> &vec);
void merge_sort(std::vector<int> &vec);

void quick_sort(std::vector<int> &vec, int lo, int hi);

int partition(std::vector<int> &vec, int lo, int hi);

std::vector<int> counting_sort(std::vector<int> &vec, int range);

#endif /* ifndef SORTING_H */
