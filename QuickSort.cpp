#include <iostream>
#include <fstream>
#define MAX 500100
using namespace std;

ifstream in("algsort.in");
ofstream out("algsort.out");
int A[MAX];

void QUICKSORT(int A[], int inf, int sup) {
  int x, i, j, t;
  i = inf;
  j = sup;
  x = A[(i + j) / 2];
  do {
    while ( (i < sup) && (A[i] < x) ) i++;
    while ( (j > inf) && (A[j] > x) ) j--;
    if ( i <= j ) {
      t = A[i];
      A[i] = A[j];
      A[j] = t;
      i++;
      j--;
    }
  } while ( i <= j );
  if ( inf < j ) QUICKSORT(inf, j);
  if ( i < sup ) QUICKSORT(i, sup);
}
int main() {
    int N;
    in>>N;
    for(int i=1;i<=N;i++)
        in>>A[i];
    QUICKSORT(1,N);
 
    for(int i=1;i<=N;i++)
        out<<A[i]<<" ";
 
 
    return 0;
}
