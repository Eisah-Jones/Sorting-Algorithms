#include "alg_tools.cpp"
#include "project1.h"


using namespace std;

void bubble_sort(vector<int>& vec)
{
  int swaps = 1;
  while(swaps)
  {
    swaps = 0;
    for(vector<int>::iterator it = vec.begin(); it != vec.end()-1; it++)
    {
      if(*(it+1) < *it)
      {
        iter_swap(it, it+1);
        swaps++;
      }
    }
  }
}

