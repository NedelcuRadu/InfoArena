```cpp
#include <iostream>
#include <fstream>
using namespace std;
ifstream in("modulo.in");
ofstream out("modulo.out");


long long int lgput(long long int A, long long int  B, long long int C) {
    long long int y = 1;
    if(B == 0 || A == 1)
        return 1;
    while(B > 1)
        if(B % 2 == 0) {
            B = B / 2;
            A = A * A % C;

        } else {
            B = (B - 1) / 2;
            y = y * A % C;
            A = A * A % C;
        }

    return A * y % C;
}
int main() {
    long long int  A, B, C;
    in >> A >> B >> C;
    out << lgput(A, B, C);
    return 0;
}
```
