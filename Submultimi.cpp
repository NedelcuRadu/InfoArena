#include <iostream>
#include <fstream>
using namespace std;
fstream in("submultimi.in");
ofstream out("submultimi.out");

int N;
int a[100];

bool ok(int k) {
    if(k == 1)
        return 1;
    if(a[k] > a[k - 1])
        return 1;
    return 0;
}

void afis(int k) {
    for(int i = 1; i <= k; i++)
        out << a[i] << " ";
    out << '\n';
}

void backtrack(int k) {
    for(int i = 1; i <= N; i++) {
        a[k] = i;
        if(ok(k)) {
            afis(k);
            backtrack(k + 1);
        }
    }
    a[k] = 0;
}

int main() {
    in >> N;
    backtrack(1);
    return 0;
}
