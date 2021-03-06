```cpp
#include <iostream>
#include <fstream>
using namespace std;

ifstream in("cmmdc.in");
ofstream out("cmmdc.out");

int cmmdc(int a, int b) {
    if(a * b == 0)
        return a;
    return cmmdc(b, a % b);
}
int main() {
    int a, b, k;
    in >> a >> b;

    k = cmmdc(a, b);

    if(k == 1)
        out << "0";
    else
        out << k;

    return 0;
}
```
