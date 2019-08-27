#include "project1.h"

using namespace std;


void spin_the_bottle_sort(vector<int>& vec)
{
  do
  {
    int i = 0;
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); i++, it++)
    {
      int randomIndex = rand() % vec.size();
      vector<int>::iterator random = it + (randomIndex - i);
      if((i < randomIndex && *it > *random) ||
         (i > randomIndex && *it < *random))
        iter_swap(it, random);
    }
  }
  while(!is_vec_sorted(vec.begin(), vec.end()));
}


