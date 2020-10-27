#include <iostream>
#include <bits/stdc++.h>
#define MAX 100004
using namespace std;
ifstream in("ctc.in");
ofstream out("ctc.out");
int N,M,x,y; // N - nr noduri, M - nr muchii
vector<int> Graph[MAX]; // Matrice de adiacenta
int ids[MAX]; // Array pt id-urile initiale
int lowLink[MAX]; // Array pt lowLinks
bool OnStack[MAX]; // Daca nodul e pe stack
stack<int> Stack; // Stack-ul cu noduri
int id = 0; // Variabila pt id-uri
int counter = 0; // Nr de componente tare conexe
int check=0;
vector<int> answer[MAX]; // Transform vectorul de lowLinks in componentele tari conexe

void DFS(int nod)
{
    //Punem nodul pe stack
    Stack.push(nod);
    OnStack[nod] = true;

    // Ii pun un ID
    ids[nod] = id;
    // LowLink-ul initial e egal cu id-ul
    lowLink[nod] = id;
    // Updatam variabila
    id++;
    //Fac un DFS
    for(int i=0; i<Graph[nod].size(); i++)
    {
        if(ids[Graph[nod][i]]==0) // Daca nodul e nevizitat
            DFS(Graph[nod][i]);

        if(OnStack[Graph[nod][i]]) // Daca e pe stack putem da update la lowLink
            lowLink[nod] = min(lowLink[nod], lowLink[Graph[nod][i]]); // lowLink-ul e minimul dintre lowLink-ul curent si cel al vecinului
    }
    //Daca am gasit componenta conexa (id == lowLink) , scoatem de pe stack
    if(ids[nod]==lowLink[nod])
    {
        while(!Stack.empty())
        {
            int nodCurent = Stack.top();
            Stack.pop();
            OnStack[nodCurent]=false;
            lowLink[nodCurent]=ids[nod];
            if(nodCurent==nod)
                break;
        }
        //counter++;
    }
}

int main()
{
    in>>N>>M;
    for(int i=1; i<=M; i++)
    {
        in>>x>>y;
        Graph[x].push_back(y);
    }

    memset(ids,0,sizeof(ids));
    memset(lowLink,0, sizeof(lowLink));
    memset(OnStack,0,sizeof(OnStack));

    for(int i=1; i<=N; i++)
        if(ids[i]==0)
            DFS(i);


    for(int i=1; i<=N; i++)
        answer[lowLink[i]].push_back(i);
    for(int i=0; i<MAX; i++)
        if(answer[i].size()!=0)
            check+=1;
    out<<check<<'\n';
    for(int i=0; i<MAX; i++)
    {
        if(answer[i].size()!=0)
        {
            check+=1;
            for(auto temp : answer[i])
                out<<temp<<" ";
            out<<'\n';
        }
    }
    return 0;
}
