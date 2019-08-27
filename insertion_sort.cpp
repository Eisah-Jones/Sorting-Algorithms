#include "project1.h"

using namespace std;

void insertion_sort(vector<int>& vec)
{
  int i = 1;
  for(vector<int>::iterator it = vec.begin()+1; it != vec.end(); i++, it++)
  {
    int j = 1;
    int a = *it;
    int b = *(it-j);
    while(b > a && (j-i) != 1)
    {
      *(it-j+1) = b;
      b = *(it-j-1);
      j++;
    }
    *(it-j+1) = a;
  }
}


