#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream in("damesah.in");
ofstream out("damesah.out");
int st[20], N;
int total = 1;
bool prima = true;
bool ok(int k) {

    for(int i = 1; i < k; i++)
        if (abs(k - i) == abs(st[k] - st[i]) || st[k] == st[i])
            return 0;
    return 1;
}
void afisare() {
    for(int i = 1; i <= N; i++)
        out << st[i] << " ";
    out << "\n";
}

void bkt(int k) {
    for (int i = 1; i <= N; i++) {
        st[k] = i;
        if (ok(k)) {
            if (k == N) {
                if (prima) {
                    afisare();
                    prima = false;
                } else
                    total += 1;
            } else
                bkt(k + 1);

        }
    }

}
int main() {
    in >> N;
    bkt(1);
    out << total;
    return 0;
}
