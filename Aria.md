```cpp
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;
ifstream in("aria.in");
ofstream out("aria.out");
 
struct punct { 
    long double x; // Double in loc de float pt precizie
    long double y;
};
 
long double arie(punct a, punct b) {
    return (a.x * b.y - a.y * b.x);
}
int main() {
    punct A, B, C;
    long double S = 0;
 
    int N;
    in >> N;
    in >> A.x >> A.y;
    C = A;
    for(int i = 1; i < N; i++) {
        in >> B.x >> B.y;
        S = S + arie(A, B);
        A = B;
    }
    S = S + arie(A, C);
    out << setprecision(6) << fixed << 0.5 * abs(S);
 
    return 0;
}
```