#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
fstream in("dfs.in");
ofstream out("dfs.out");
int N, M;
bool viz[100005] = {0};
vector<int> A[100005];
void DFS(int nod) {
    viz[nod] = 1;
    for(int i = 0; i < A[nod].size(); i++)
        if(!viz[A[nod][i]])
            DFS(A[nod][i]);
}
int main() {
    in >> N >> M;
    int x, y;
    int cnt = 0;
    for(int i = 1; i <= M; i++) {
        in >> x >> y;
        A[x].push_back(y);
        A[y].push_back(x);
    }

    for(int i = 1; i <= N; i++)
        if(!viz[i]) {
            DFS(i);
            cnt++;
        }
    out << cnt;
    return 0;
}
