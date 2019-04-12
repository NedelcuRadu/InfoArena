#include <bits/stdc++.h>
#define MAX 50005
using namespace std;
ifstream in("sortaret.in");
ofstream out("sortaret.out");

//Complexitate O(N+M)
int N, M;
vector<int> A[MAX];
vector<int> S;
bool viz[MAX];

void citire() {
    int x, y;
    in >> N >> M;
    while(M--) {
        in >> x >> y;
        A[x].push_back(y);
    }
}

void DFS(int nod) { //Facem o parcurgere DFS si retinem nodurile
    viz[nod] = 1;
    for(int i = 0; i < A[nod].size(); i++)
        if(!viz[A[nod][i]])
            DFS(A[nod][i]);
    S.push_back(nod);
}

int main() {
    citire();
    for(int i = 1; i <= N; i++)
        if(!viz[i])
            DFS(i);

    for(int i = S.size() - 1; i >= 0; i--)
        out << S[i] << " ";

}
