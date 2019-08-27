#ifndef PROJECT1_H
#define PROJECT1_H

#include <vector>

void bubble_sort(std::vector<int>& vec);
void insertion_sort(std::vector<int>& vec);
void spin_the_bottle_sort(std::vector<int>& vec);
void shell_sort(std::vector<int>& vec, const std::vector<int>& gaps);
void annealing_sort(std::vector<int>& vec, const std::vector<int>& temps, const std::vector<int>& reps);

#endif
