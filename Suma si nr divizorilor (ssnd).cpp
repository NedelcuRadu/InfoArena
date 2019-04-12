#include <iostream>
#include <fstream>
#define MOD 9973
#define MAX 1000000
using namespace std;
ifstream in("ssnd.in");
ofstream out("ssnd.out");



void sieve(bool A[]) { //Ciurul lui Erathostenes
    A[1] = 0;
    for(int i = 2; i <= MAX; i++)
        A[i] = 1;
    for(long long int i = 2; i * i <= MAX; i++)
        if(A[i])
            for(long long int j = i * i; j <= MAX; j = j + i)
                A[j] = 0;
}

long long int exp(long long int x, long long int y) { //Exponentiere in timp logaritmic
    long long int z = 1;
    while(y > 1) {
        if(y % 2 == 0) {
            y = y / 2;
            x = x * x;
        } else {
            z = z * x;
            y = (y - 1) / 2;
            x = x * x;
        }
    }
    return x * z;
}

void solve(long long int n, bool A[], int B[]) {
    int S = 1;
    int nr = 1;
    int k = 0;
    int i = 1;

    while(n > 1) {

        while(n % B[i] == 0) { //Aflam de cate ori se divide
            n = n / B[i];
            k++;
        }
        if(k != 0) {
            //long long int p = round(pow(i, k + 1));
            S = S * (exp(B[i], k + 1) - 1) / (B[i] - 1) % MOD;
            nr = nr * (k + 1);
            k = 0;
        }

        if(n <= MAX) { //Daca n e prim nu mai cautam divizori
            if(A[n]) {
                
                S = S * (exp(n, 2) - 1) / (n - 1) % MOD;
                nr = nr * 2;
                n = 1;
            }
        }

        i++;
    }


    if(nr == 1) //Daca e prim
        out << 2 << " " << (n + 1) % MOD << '\n';
    else
        out << nr << " " << S << '\n';


}

int main() {
    bool A[MAX];
    int B[100000], t, poz = 1;
    long long int n;

    sieve(A); //Marcam nr prime pana la MAX
    for(int i = 1; i <= MAX; i++) //Punem doar nr prime in B
        if(A[i]) {
            B[poz] = i;
            poz++;
        }

    in >> t; //Nr de intrebari
    for(int i = 1; i <= t; i++) { //Solutie
        in >> n;
        solve(n, A, B);
    }

    return 0;
}

