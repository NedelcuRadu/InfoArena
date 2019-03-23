
#include <vector>  
#include <fstream>  
#include <algorithm>  
#include <iostream>  
  
using namespace std;

ifstream in("algsort.in");
ofstream out("algsort.out");

int N;
vector <int>V;

int main() {
    in >> N;  
    int x;  
    for(int i = 1; i <= N; i++) {  
        in >> x;  
        V.push_back(x);  
    }  
    sort(V.begin(), V.end());  
    for(int i = 0; i < N; i++)  
        out << V[i] << " ";  
    return 0;  
}  
