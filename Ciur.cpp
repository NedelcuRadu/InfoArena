#include <iostream>
#include <fstream>
#include <math.h>
#define MAX 2000100
using namespace std;

ifstream in("ciur.in");
ofstream out("ciur.out");

bool A[MAX];

void SieveOfErathostene(long int p) {
    for(long int i = 1; i <= p; i++) //Initializam ciurul
        A[i] = 1;
    for(long int i = 2; i <= sqrt(p); i++) //Nu are sens sa verificam nr mai mari decat sqrt
        if(A[i]) {
            for(long int j = i * i; j <= p; j = j + i) // Marcam ca nefiind prime
                A[j] = 0;
        }
}

int main() {
    long int n, k = 0;
    in >> n;
    SieveOfErathostene(n);
    for(int i = 2; i <= n; i++)
        if(A[i])
            k++;
    out << k;
    return 0;
}
