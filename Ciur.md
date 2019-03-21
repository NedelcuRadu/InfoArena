```cpp
#include <iostream>
#include <fstream>
#include <math.h>
#define MAX 2000100
using namespace std;

ifstream in("ciur.in");
ofstream out("ciur.out");

bool A[MAX];

void SieveOfErathostene(long int p) {
    for(long int i = 1; i <= p; i++)
        A[i] = 1;
    for(long int i = 2; i <= sqrt(p); i++)
        if(A[i]) {
            for(long int j = i * i; j <= p; j = j + i)
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
```