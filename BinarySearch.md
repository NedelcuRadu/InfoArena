```cpp
#include <iostream>
#include <fstream>
#define N 100010
using namespace std;
ifstream in("cautbin.in");
ofstream out("cautbin.out");
int A[N];
 
int binarysearch0(int val, int n) {
    int i, step;
    for(step=1; step<=n; step<<=1);
    for(i=0; step; step>>=1)
        if(i+step<=n && A[i+step]<=val)
            i+=step;
    if(A[i]!=val)
        return -1;
    return i;
}
 
int binarysearch1(int val,int n) {
    int i,step;
    for(step=1; step<=n; step<<=1);
    for(i=0; step; step>>=1)
        if(i+step<=n && A[i+step]<=val)
            i+=step;
    return i;
}
 
int binarysearch2(int val, int n) {
    int i,step;
    for(step=1; step<=n; step<<=1);
    for(i=0; step; step>>=1)
        if(i+step<=n && A[i+step]<val)
            i+=step;
    return i+1;
}
 
int main() {
    int n,M,tip,val;
    in>>n;
    for(int i=1; i<=n; i++)
        in>>A[i];
    in>>M;
    for(int i=1; i<=M; i++) {
        in>>tip>>val;
        if(tip==0)
            out<<binarysearch0(val,n);
        else if (tip==1)
            out<<binarysearch1(val,n);
                else
                    out<<binarysearch2(val,n);
        out<<'\n';
    }
 
 
    return 0;
}
```
