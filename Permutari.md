```cpp
#include <iostream>
#include <fstream>
using namespace std;

ifstream in("permutari.in");
ofstream out("permutari.out");

int N,st[10];

void afis() {
    for(int i=1; i<=N; i++)
        out<<st[i]<<" ";
    out<<'\n';
}

bool ok(int k) {
    if(k==1)
        return 1;
    else
        for(int i=1; i<k; i++)
            if(st[i]==st[k])
                return 0;
    return 1;

}

void backtrack(int k) {
    for(int i=1; i<=N; i++) {
        st[k]=i;
        if(ok(k)) {
            if(k==N)
                afis();
            else
                backtrack(k+1);
        }
        st[k]=1;
    }
}

int main() {
    in>>N;
    backtrack(1);
    return 0;
}
```
