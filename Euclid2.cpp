```cpp
#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");
 
long int euclid(long int a, long int b) {
    if (b == 0)
        return a;
    return euclid(b, a % b);
}
 
int main() {
    int T, a, b;
    in >> T;
    for(int i = 1; i <= T; i++) {
        in >> a >> b;
        out << euclid(a, b) << '\n';
 
    }
 
    return 0;
}
```
