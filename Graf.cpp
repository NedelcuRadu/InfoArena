//Vom face cate o parcurgere in latime din cele 2 noduri date
//Vom vedea care noduri fac parte din drumul minim
//Din cele ce fac parte din drumul minim vedem la care se poate ajunge intr-un singur mod 
#include <bits/stdc++.h>
#define MAX 7510
using namespace std;
ifstream in("graf.in");
ofstream out("graf.out");

vector<int> A[MAX];
int N,M,X,Y;
int viz[MAX];
int costX[MAX];
int costY[MAX];
int S[MAX];

void citire() //Lista de adiacenta
{
    int a,b;
    in>>N>>M>>X>>Y;
    for(int i=1; i<=M; i++)
    {
        in>>a>>b;
        A[a].push_back(b);
        A[b].push_back(a);
    }
}

int BFSX(int nod) //Parcurgerea din X
{
    memset(costX,-1,sizeof(costX));
    int L=1;
    S[L]=nod;
    costX[nod]=0;
    for(int i=1; i<=L; i++)
        for(int j=0; j<A[S[i]].size(); j++)
        {
            if(costX[A[S[i]][j]]==-1)
            {
                S[++L]=A[S[i]][j];
                costX[S[L]]=costX[S[i]]+1;
            }
        }


}

int BFSY(int nod) //Parcurgerea din Y
{
    memset(costY,-1,sizeof(costY));
    int L=1;
    S[L]=nod;
    costY[nod]=0;
    for(int i=1; i<=L; i++)
        for(int j=0; j<A[S[i]].size(); j++)
        {
            if(costY[A[S[i]][j]]==-1)
            {
                S[++L]=A[S[i]][j];
                costY[S[L]]=costY[S[i]]+1;
            }
        }

}

int main()
{
    citire();
    BFSX(X);
    BFSY(Y);

    int val_min=costX[Y];

    for(int i=1; i<=N; i++)
        if(costX[i]+costY[i]==val_min) //Daca nodurile fac parte din cel mai scurt drum
            viz[costX[i]]++;
            
    int vec_fin[MAX];
    int ct=0;


    for(int i=1; i<=N; i++)
        if(costX[i]+costY[i]==val_min) //Daca face parte din cel mai scurt drum si doar prin el se poate trece
            if(viz[costX[i]]==1 ) vec_fin[++ct]=i;
            
    out<<ct<<endl;
    
    for(int i=1; i<=ct; i++)
        out<<vec_fin[i]<<" ";
        
    return 0;
}
