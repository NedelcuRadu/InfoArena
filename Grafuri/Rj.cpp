#include <iostream>
#include <bits/stdc++.h>
#define MAX 102
using namespace std;
ifstream in("rj.in");
ofstream out("rj.out");
int N,M;
char linie[MAX+2];
int R[MAX][MAX];
int J[MAX][MAX];
pair<int,int> Romeo;
pair<int,int> Julieta;
int move_i[] = {0,0,1,1,1,-1,-1,-1};
int move_j[] = {1,-1,0,1,-1,-1,0,1};
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
    if(i<1 || j<1 || j>M || i > N || A[i][j]!=0)
        return false;
    return true;

}
void Lee(int A[MAX][MAX], int starti, int startj)
{
    int currentI, currentJ, nextI, nextJ;
    queue<pair<int,int>> que;
    que.push({starti,startj});
    A[starti][startj] = 1;
    while(!que.empty()) // Cat timp coada nu e goala
    {
        currentI = que.front().first; // Iau coord actuale;
        currentJ = que.front().second;
        que.pop(); // Elimin el curent
        //Verific vecinii
        for(int i=0; i<8; i++)
        {
            nextI = currentI + move_i[i];
            nextJ = currentJ + move_j[i];
            if(ok(A, nextI, nextJ)) // Daca e mutare valida
            {
                A[nextI][nextJ] = A[currentI][currentJ]+1; // Cresc costul
                que.push({nextI,nextJ}); // Bag in coada
            }
        }
    }
}
int main()
{
    in>>N>>M;
    in.getline(linie, 1+M);
    for(int i=1; i<=N; i++)
    {
        in.getline(linie, 1+M);
        for(int k=0; k<M; k++)
            if(linie[k]=='R')
            {
                R[i][k+1]=0;
                J[i][k+1]=0;
                Romeo = {i,k+1};
            }
            else if(linie[k]=='J')
            {
                R[i][k+1]=0;
                J[i][k+1]=0;
                Julieta = {i,k+1};
            }
            else if(linie[k]=='X')
            {
                R[i][k+1]=-1;
                J[i][k+1]=-1;
            }
            else
            {
                R[i][k+1]=0;
                J[i][k+1]=0;
            }
    }
    Lee(R,Romeo.first,Romeo.second);
    Lee(J,Julieta.first,Julieta.second);
    int minimT=2e9;
    pair<int,int> answer;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
        {
            if(R[i][j]>0 && (R[i][j]==J[i][j]) && R[i][j]<minimT)
            {
                minimT = R[i][j];
                answer = {i,j};
            }
        }
    out<<minimT<<" "<<answer.first<<" "<<answer.second;
    return 0;
}
