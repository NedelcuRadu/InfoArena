#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

#define MAX 100100

using namespace std;
fstream in("bfs.in");
ofstream out("bfs.out");

vector<int> A[MAX];
int N, M, Start, L;
int cost[MAX];
int S[MAX];

void BFS(int nod) {
    L = 1;
    S[L] = nod; //Add the node to the queue
    cost[nod] = 0; //Cost to same node is 0
    for(int i = 1; i <= L; i++) //While queue is not empty
        for(int j = 0; j < A[S[i]].size(); j++) // Check the neighbours
            if(cost[A[S[i]][j]] == -1) { //If not visited already
                S[++L] = A[S[i]][j]; //Add to queue
                cost[S[L]] = cost[S[i]] + 1; //Increase cost of neighbour
            }



}
int main() {
    in >> N >> M >> Start;
    int x, y;
    for(int i = 1; i <= M; i++) {
        in >> x >> y;
        A[x].push_back(y); //Read as adiacency list
    }
    memset(cost, -1, sizeof(cost)); //Set all the costs to -1
    
    BFS(Start);
    
    for(int i = 1; i <= N; i++)
        out << cost[i] << " ";
    return 0;
}
