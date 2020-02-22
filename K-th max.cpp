#include <iostream>
#include <fstream>
#include <vector>
#include <random>
using namespace std;
ifstream in("sdo.in");
ofstream out("sdo.out");

int QuickSelect(vector<int>&Nr, int K) { // Vectorul initial, cate nr, al catelea maxim
    vector<int> L, E, G;
    int pivot = Nr[rand()%Nr.size()];
    for(auto i : Nr) {
        if (i < pivot)
            L.push_back(i);
        else if (i == pivot)
            E.push_back(i);
        else
            G.push_back(i);
    }
    if (K < L.size())
        return QuickSelect(L, K);
    else if (K < L.size() + E.size())
        return E[0];
    else
        return QuickSelect(G,K - L.size() - E.size());
}

int main() {
    int N, K;
    vector<int> A;
    in >> N >> K;
    for( auto i = 0; i < N; i++) {
        int temp;
        in >> temp;
        A.push_back(temp);
    }
    out << QuickSelect(A, K-1) << endl;

}
