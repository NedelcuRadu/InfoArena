// Cu priority Que
#include <iostream>
#include <bits/stdc++.h>
#define MAX 50005
using namespace std;
ifstream in("dijkstra.in");
ofstream out("dijkstra.out");
int N,M;
int d[MAX];
bool viz[MAX];
vector<pair<int,int>> Graph[MAX];
auto Compare = [](pair<int,int> &a, pair<int,int> &b)
{
    return (a.second>b.second);
};
priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(Compare) > que(Compare);

int main()
{
    in>>N>>M;
    int x,y,z;
    for(int i=1; i<=M; i++)
    {
        in>>x>>y>>z;
        Graph[x].push_back({y,z});
    }
    for(int i=1; i<=N; i++)
        d[i]=2e9;
    d[1] = 0; //Pornesc din 1
    que.push({1,0});

    while(!que.empty())
    {
        int u = que.top().first;
        que.pop();
        if(viz[u])
            continue;
        viz[u] = true;
        for(auto &vecin:Graph[u])
        {
            int v = vecin.first;
            int w = vecin.second;
            if(w+d[u]<d[v])
            {
                d[v] = w+d[u];
                que.push({v,d[v]});
            }
        }
    }
    for(int i=2; i<=N; i++)
        if(d[i]!=2e9)
            out<<d[i]<<" ";
        else
            out<<0<<" ";
    return 0;
}
