#include <iostream>
#include <fstream>
#define MAX 10000
using namespace std;
fstream in("input.in");
int W,N; //Greutate, nr obiecte
int values[MAX],weights[MAX];
bool taken[MAX];
int DP[MAX][MAX];
int main()
{
    in>>W>>N;
    for(int i=1; i<=N; i++)
        in>>values[i];
    for(int i=1; i<=N; i++)
        in>>weights[i];
    for(int i=0; i<=W; i++)
        DP[0][i]=0;
    for(int i=1; i<=N; i++)
        DP[i][0]=0;
    for(int i=1; i<=N; i++)
        for(int j=0; j<=W; j++)
            if(weights[i]<=j)
                DP[i][j] = max(DP[i-1][j], values[i]+DP[i-1][j-weights[i]]);
            else
                DP[i][j] = DP[i-1][j];
    cout<<DP[N][W]<<'\n';
    int ans = DP[N][W];
    int w = W;
   for(int i=N;i>0;i--)
   {
       if(ans == DP[i-1][w]) // Valoarea e aceeasi cu valoarea daca nu am fi luat obiectul, deci nu e inclus
        continue;
       else // Daca e inclus, il marcam, updatam valoarea si greutatea
       {
           taken[i]=1;
           ans -= values[i];
           w -= weights[i];
       }
   }
   for(int i=1;i<=N;i++)
    cout<<taken[i]<<" ";
    return 0;
}
