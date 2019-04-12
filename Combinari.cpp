#include <iostream>
#include <fstream>
using namespace std;

ifstream in("combinari.in");
ofstream out("combinari.out");


int N,K, st[20];

void afis() { //Functie de afisare a solutiei
    for(int i=1; i<=K; i++)
        out<<st[i]<<" ";
        out<<'\n';
}

bool ok(int p) { //Functie de verificare 
    if(p==1)
        return 1;
    if(st[p]>st[p-1])
        return 1;
    return 0;
}

void backtrack(int p) {
    for(int i=1; i<=N; i++){
    st[p]=i;
        if(ok(p)) {
            if(p==K)
                afis();
            else
                backtrack(p+1);
        }
        st[p]=0;}
}

int main() {
 in>>N>>K;
 backtrack(1);
    return 0;
}
