#include <iostream>
#include <fstream>
#define MOD 1999999973
using namespace std;
ifstream in("lgput.in");
ofstream out("lgput.out");

long long int N, P;

long long int lgput(long long  int N, long long int P) {
    long long int y = 1;
    if(P == 0 || N == 1) //Daca baza e 1 sau exponentul e 0
        return 1;
    while(P > 1) // Cat timp exponentul > 1
        if(P % 2 == 0) { //Daca e divizibil cu 2 putem afla patratul lui N si sa injumatatim exponentul
            N = N * N % MOD;
            P = P / 2;
        } else { //Altfel retinem cu cat mai trebuia inmultit
            y = y * N % MOD;
            N = N * N % MOD;
            P = (P - 1) / 2;

        }
    return N * y % MOD;
}

int main() {
    in >> N >> P;
    out << lgput(N, P);

    return 0;
}
