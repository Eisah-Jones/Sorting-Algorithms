#ifndef ALG_TOOLS_CPP
#define ALG_TOOLS_CPP

#include <vector>
#include <algorithm>
#include <math.h>
#include <random>

using namespace std;


int getUniformRandomInt(int a, int b, mt19937& mt)
{
  if (a == b){
    uniform_int_distribution<int> dist{a, b};
    return dist(mt);}
  else{
    uniform_int_distribution<int> dist{a, b-1};
    return dist(mt);}
}


void almost_shuffle_vector(vector<int>& v, int n)
{
  random_device rd{};
  mt19937 mt(rd());
  for(int i = 0; i < 2*log(n); i++)
  {
    int a = getUniformRandomInt(0, n, mt);
    int b = getUniformRandomInt(0, n, mt);
    
    int temp = v[a];
    v[b] = v[a];
    v[a] = temp;
  }
}



void shuffle_vector(vector<int>& v, int n)
{
  random_device rd{};
  mt19937 mt(rd());
  for(int i = 0; i < n; i++)
  {
    int random = getUniformRandomInt(0, n, mt);
    int temp = v[i];
    v[i] = v[random];
    v[random] = temp;
  }
}


vector<int> generateAlmostSortedVector(int n)
{
  vector<int> result = vector<int>(n);
  for(int i = 0; i < n; i++)
    result[i] = (i+1);
  
  random_device rd{};
  mt19937 mt(rd());
  for(int i = 0; i < 2*log(n); i++)
  {
    int a = getUniformRandomInt(0, n, mt);
    int b = getUniformRandomInt(0, n, mt);
    
    int temp = result[a];
    result[b] = result[a];
    result[a] = temp;
  }
  return result;
}


vector<int> generateUniformVector(int n)
{
  vector<int> result = vector<int>(n);
  for(int i = 0; i < n; i++)
    result[i] = (i+1);
  shuffle_vector(result, n);
  return result;
}


bool is_vec_sorted(const vector<int>::iterator start, const vector<int>::iterator end)
{
  for(vector<int>::iterator it = start+1; it != end; it++)
  {
    if(*(it-1)>*it)
      return false;
  }
  return true;
}


vector<int> getTemps(int n, int i)
{
  vector<int> result;
  int v;

  if(i == 2) v = 2*n;
  else v = 1;
  for(int i = 10; i > 0; i--)
  {
    if(i == 1)
      v = 10;
    else if(i == 2 && i%2 == 1)
      v /= 2;    
    result.push_back(v);
  }
  return result;
}


vector<int> getReps(int n, int i)
{
  vector<int> result;
  int v;
  for(int i = 10; i > 0; i--)
  {
    if(i == 1)
      v = 5;
    else
      v = (int) log(n)/log(log(n));
    
    result.push_back(v);
  }

  return result;
}


vector<int> getGaps(int n, int i)
{
  vector<int> result;
  int v;
  for(int i = 10; i > 0; i--)
  {
    if(i == 1)
      v = pow(2, i) - 1;
    else
      v = pow(4, i) + 3 * pow(2, i-1) + 1;
    
    result.push_back(v);
  }

  return result;
}


void vecSwap(vector<int>& v, int a, int b)
{
  int temp = v[a];
  v[b] = v[a];
  v[a] = temp;
}


#endif







