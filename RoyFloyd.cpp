#include <iostream>
#include <fstream>
#define MAX 105
#define INF 1005
using namespace std;

ifstream in("royfloyd.in");
ofstream out("royfloyd.out");

int A[MAX][MAX];
int N;

void citire() {
    in >> N;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            {in >> A[i][j];
            if(A[i][j]==0)
                A[i][j]=INF;
            }
}

void RoyFloyd() {
    for(int k = 1; k <= N; k++)
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                A[i][j] = min(A[i][j],A[i][k]+A[k][j]);
}

int main() {
    citire();
    RoyFloyd();
 
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++)
            if(i==j || A[i][j]==INF)
            out<<"0 ";
        else
            out << A[i][j] << " ";
        out << endl;
    }
    return 0;
}
