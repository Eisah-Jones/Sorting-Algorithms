#include "project1.h"

using namespace std;


void annealing_sort(vector<int>& vec, const vector<int>& temps, const vector<int>& reps)
{
  random_device rd{};
  mt19937 mt(rd());
  do
  {
    for(int j = 0; j < temps.size(); j++)
    {
      int temp = temps[j];
      int rep = reps[j];
      for(int i = 0; i < vec.size()-1; i++)
      { 
        for(int k = 0; k < rep; k++)
        {
          int randomIndex = getUniformRandomInt(i+1, min(((int)vec.size()), i+temp), mt);
          int random = vec[randomIndex];
          if(vec[i] > random)
            vecSwap(vec, i, randomIndex);
        }
      }
      
      for(int i = vec.size(); i >= 2; i--)
      { 
        for(int k = 0; k < rep; k++)
        {
          int randomIndex = getUniformRandomInt(max(0, i-temp), i, mt);
          int random = vec[randomIndex];
          if(vec[i] < random)
            vecSwap(vec, i, randomIndex);
        }
      }
    }
  }
  while(!is_vec_sorted(vec.begin(), vec.end()));
}


