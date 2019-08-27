#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "alg_tools.cpp"
#include "bubble_sort.cpp"
#include "insertion_sort.cpp"
#include "spin_the_bottle_sort.cpp"
#include "shell_sort.cpp"
#include "annealing_sort.cpp"

using namespace std;

void createTimingsFile(string fileName)
{
  ofstream f;
  f.open(fileName.c_str(), ios::trunc);
  f << "funcname,dist,n,seconds\n";
  f.close();
}


void writeReportTime(string fileName, string func, string dist, int n, float time)
{
  ofstream f;
  f.open(fileName.c_str(), ios::app);
  f << func << ',' << dist << ',' << n << ',' << time << "\n";
  f.close();
}


void printReport(float accuracy, double time)
{
  printf("        **************************\n");
  printf("        Report:\n");
  printf("         - Accuracy: %.2f%\n", accuracy);
  printf("         - Tot time: %.2f secs\n", time);
  printf("        **************************\n");
}


void RunSortingAlgorithms(int n, int reps)
{
  string algorithms[] = {"Bubble", "Insertion", "Spin-the-Bottle", "Shell1", "Shell2", "Annealing1", "Annealing2"};

  createTimingsFile("data/timings.csv");

  for(int algIdx = 0; algIdx < n; algIdx++)
  {
    string a = *(algorithms + algIdx);
    printf("[Start] %s Sort Analysis\n", a.c_str());

    vector<int> vec, gapVec, tempVec, repVec;

    int total_correct = 0;
    int total_progress = 0;
    int progress, correct;
    int total = 0;

    clock_t start, end;
    float time;
    double total_time = 0.0;

    for(int vecLen = 10; vecLen <= 10000; vecLen *= 10)
    {
       printf("        n = %d\n", vecLen);
       int total_prog = 0;
       int total_rep_time = 0;
       correct = 0;
       for(int vectDistribution = 0; vectDistribution < 2; vectDistribution++)
       {
         progress = 1;
         double rep_time = 0.0;
         if (!vectDistribution)
         {
           printf("           Distrib: Uniform\n");  
           vec = generateUniformVector(vecLen);
         }
         else
         {
           printf("           Distrib: Almost-Sorted\n");
           vec = generateAlmostSortedVector(vecLen);
         }

         if(algIdx == 3 || algIdx == 5)
           printf("          Sequence: 1");
         else if (algIdx == 4 || algIdx == 6)
           printf("          Sequence: 2");
         

         printf("          Progress: 0/%d runs", reps);
         
         for(int rep = 0; rep < reps; rep++, progress++)
         {
           switch(algIdx)
           {
             case 0:
               start = clock();
               bubble_sort(vec);
               end = clock();
               break;
             case 1:
               start = clock();
               insertion_sort(vec);
               end = clock();
               break;
             case 2:
               start = clock();
               spin_the_bottle_sort(vec);
               end = clock();
               break;
             case 3:
               gapVec = getGaps(vecLen, 1);
               start = clock();
               shell_sort(vec, gapVec);
               end = clock();
               break;
             case 4:
               gapVec = getGaps(vecLen, 2);
               start = clock();
               shell_sort(vec, gapVec);
               end = clock();
               break;
             case 5:
               tempVec = getTemps(vecLen, 1);
               repVec = getReps(vecLen, 1);
               start = clock();
               annealing_sort(vec, tempVec, repVec);
               end = clock();
               break; 
             case 6:
               tempVec = getTemps(vecLen, 2);
               repVec = getReps(vecLen, 2);
               start = clock();
               annealing_sort(vec, tempVec, repVec);
               end = clock();
               break; 
           }
           total_prog += progress;
           total_rep_time += rep_time;
           if(is_vec_sorted(vec.begin(), vec.end()))
             correct++;
           time = (float) (end - start) / CLOCKS_PER_SEC;
           total_time += time;
           rep_time += time;
           printf("\r          Progress: %04d/%d runs", progress, reps);
           if(!vectDistribution)
             shuffle_vector(vec, vecLen);
           else
             almost_shuffle_vector(vec, vecLen);
         }
         float avgRepTime = (float) rep_time/reps;
         string dist;
         if (vectDistribution == 0) dist = "Uniform";
         else dist = "Almost Sorted";
         writeReportTime("data/timings.csv", a, dist, vecLen, avgRepTime);
         printf("\n          Avg Time: %f secs\n\n", avgRepTime); 
       }
      total_correct += correct;
      total_progress += progress;
    }
    printReport(total_correct/total_progress*100, total_time);
    printf("[  End] %s Sort Analysis\n", a.c_str());
  }
}


int main()
{
  printf("\n----------------------------------\n");
  printf("   Running Project 1 Test Bench\n");
  printf("    Programmed by: Eisah Jones\n");
  printf("      UC Irvine, Spring 2019\n");
  printf("----------------------------------\n");
  RunSortingAlgorithms(7, 100);
  printf("\n");
  return 1;
}
