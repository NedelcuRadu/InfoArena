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
  x = A[(i + j) / 2]; //Elementul din mijloc e pivotul
  do {
    while ( (i < sup) && (A[i] < x) ) i++; //Cate elemente mai mici decat pivotul sunt
    while ( (j > inf) && (A[j] > x) ) j--; //Cate elemente mai mari decat pivotul
    if ( i <= j ) { //Le schimbam intre ele
      t = A[i];
      A[i] = A[j];
      A[j] = t;
      i++;
      j--;
    }
  } while ( i <= j );
  if ( inf < j ) QUICKSORT(A, inf, j); //Sortam bucatile ramase
  if ( i < sup ) QUICKSORT(A, i, sup);
}
int main() {
    int N;
    in>>N;
    for(int i=1;i<=N;i++)
        in>>A[i];
    QUICKSORT(A,1,N);
 
    for(int i=1;i<=N;i++)
        out<<A[i]<<" ";
 
 
    return 0;
}
