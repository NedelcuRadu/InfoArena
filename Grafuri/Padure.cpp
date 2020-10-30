#include <iostream>
#include <bits/stdc++.h>
#define MAX 1002
using namespace std;
ifstream in("padure.in");
ofstream out("padure.out");
int N,M;
int Tipuri[MAX][MAX];
int Costuri[MAX][MAX];
pair<int,int> Algorel;
pair<int,int> Castel;
int move_i[] = {0,0,1,-1};
int move_j[] = {1,-1,0,0};
void afis(int A[MAX][MAX])
{
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
            cout<<A[i][j]<<" ";
        cout<<'\n';
    }
}
bool ok(int A[MAX][MAX], int i, int j)
{
    if(i<1 || j<1 || j>M || i > N )
        return false;
    return true;

}
void Lee(int A[MAX][MAX], int starti, int startj)
{
    int currentI, currentJ, nextI, nextJ;
    deque<pair<int,int>> que;
    que.push_back({starti,startj});
    A[starti][startj] = 0;
    while(que.front().first!= Castel.first || que.front().second!= Castel.second) // Cat timp nu am ajuns la castel
    {
        currentI = que.front().first; // Iau coord actuale;
        currentJ = que.front().second;
        que.pop_front(); // Elimin el curent
        //Verific vecinii
        for(int i=0; i<4; i++)
        {
            nextI = currentI + move_i[i];
            nextJ = currentJ + move_j[i];
            if(ok(A, nextI, nextJ)&& A[nextI][nextJ]>A[currentI][currentJ]) // Daca e in matrice si are costul mai "slab"
            {
                A[nextI][nextJ] = A[currentI][currentJ];
                if(Tipuri[nextI][nextJ]!=Tipuri[currentI][currentJ])
                   {
                       A[nextI][nextJ]++; // Cresc costul daca difera tipurile de copaci
                que.push_back({nextI,nextJ}); // Bag in coada la final
                   }
                   else
                   que.push_front({nextI,nextJ}); // Au prioriate cele de acelasi tip
            }
        }
    }
}
int main()
{
    in>>N>>M>>Algorel.first>>Algorel.second>>Castel.first>>Castel.second;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
        {
            in>>Tipuri[i][j];
            Costuri[i][j]=999;
        }
    Lee(Costuri,Algorel.first,Algorel.second);
    out<<Costuri[Castel.first][Castel.second];
    return 0;
}
