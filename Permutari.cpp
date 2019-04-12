#include <iostream>
#include <fstream>
using namespace std;

ifstream in("permutari.in");
ofstream out("permutari.out");

int N,st[10];

void afis() { //Functie de afisare a solutiei
    for(int i=1; i<=N; i++)
        out<<st[i]<<" ";
    out<<'\n';
}

bool ok(int k) { //Functie de verificare
    if(k==1) //Daca e doar 1 element nu avem ce verifica
        return 1;
    else
        for(int i=1; i<k; i++) //Toate elementele trebuie sa fe diferite
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

