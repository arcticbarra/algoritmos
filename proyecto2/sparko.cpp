// #include<stdio.h>
// #include<iostream>
// #include <vector>
// //
// // using namespace std;
// // int c = 0,cost = 999;
// //
// // void swap (int *x, int *y)
// // {
// //     int temp;
// //     temp = *x;
// //     *x = *y;
// //     *y = temp;
// // }
// // void copy_array(int *a, int n, vector< vector<int> > &graph)
// // {
// //     int i, sum = 0;
// //     for(i = 0; i <= n; i++)
// //     {
// //         sum += graph[a[i % 4]][a[(i + 1) % 4]];
// //     }
// //     if (cost > sum)
// //     {
// //         cost = sum;
// //     }
// // }
// // void permute(int *a, int i, int n, vector< vector<int> > &graph)
// // {
// //    int j, k;
// //    if (i == n)
// //    {
// //         copy_array(a, n, graph);
// //    }
// //    else
// //    {
// //         for (j = i; j <= n; j++)
// //         {
// //             swap((a + i), (a + j));
// //             permute(a, i + 1, n, graph);
// //             swap((a + i), (a + j));
// //         }
// //     }
// // }
// // int main()
// // {
// //   int a[] = {0, 1, 2, 3};
// //   int k,c,cost;
// //   char x,y;
// //   cin >> k >> c;
// //   vector< vector<int> > matrix(k, vector<int>(k, 0));
// //   for (int j = 0; j < c; j++) {
// //       cin >> x >> y >> cost;
// //       matrix[x-65][y-65] = cost;
// //       matrix[y-65][x-65] = cost;
// //   }
// //   permute(a, 0, 3, matrix);
// //   cout << cost << endl;
// //   return 0;
// // }
// int dp[(1<<12)+5][12];
//
// int main() {
//     int i,j,n,ans,k,p;
//     int k,c,cost;
//     char x,y;
//     cin >> k >> c;
//     vector< vector<int> > map(k, vector<int>(k, 0));
//     for (int j = 0; j < c; j++) {
//         cin >> x >> y >> cost;
//         map[x-65][y-65] = cost;
//         map[y-65][x-65] = cost;
//     }
//     //floyd algorithm, get any two points's minimum distance
//     for (k=0; k<n; k++) {
//         for (i=0; i<n; i++) {
//             for (j=0; j<n; j++) {
//                 if (i!=j && i!=k && j!=k) map[i][j]=min(map[i][k]+map[k][j],map[i][j]);
//             }
//         }
//     }
//     memset(dp,-1,sizeof(dp));
//     dp[1][0]=0;
//     // TSP solution here,bitmask and DP
//     for (i=1; i<(1<<n); i++) {// the current state
//         for (j=0; j<n; j++) {// during the current state,the last station is j
//             if (dp[i][j]==-1) continue;
//             for (k=1; k<n; k++) {//the next state is k
//                 if ((i & (1<<k))!=0) continue;
//                 p=(i | (1<<k));// the new state(join k)
//                 if (dp[p][k]==-1) dp[p][k]=dp[i][j]+map[j][k];
//                 dp[p][k]=min(dp[p][k],dp[i][j]+map[j][k]);
//             }
//         }
//     }
//     ans=INF;
//     // get answer
//     for (i=1; i<n; i++) {
//         if (dp[(1<<n)-1][i]>0) ans=min(ans,dp[(1<<n)-1][i]+map[i][0]);
//     }
//     printf("%d\n",ans);
//     return 0;
// }


#include<iostream>
#include <queue>
#import <cmath>
using namespace std;

int iMat[50][50], iNumCasas, nivel=0;
int mejorCamino=32000;
struct Nodo
{
    int iCostoPosible, iAnterior,inivel;
    int iPasados[20];
};

struct compare
{
    bool operator()(Nodo l, Nodo r)
    {
        return l.iCostoPosible > r.iCostoPosible;
    }
};

priority_queue<Nodo,vector<Nodo>, compare > filaPriorizada;;

void inicializarMatriz(int iNumCasas)
{
    for(int i=0; i<iNumCasas; i++)
    {
        for(int j=0; j<iNumCasas; j++)
        {
            if(i == j)
                iMat[i][j] = 0;
            else
                iMat[i][j] = 32000;
        }
    }

}

void primerNodo(){
    Nodo nodo1;
    int imenor=32000, iacum=0;

    for (int i=0; i<iNumCasas; i++) {
        imenor=32000;
        for (int j=0; j<iNumCasas; j++) {
            if (i!=j)imenor= min(imenor,iMat[i][j]);
        }
        iacum+=imenor;

    }
    nodo1.iCostoPosible=iacum;
    nodo1.inivel=0;
    nivel++;
    filaPriorizada.push(nodo1);
}

void menor(int ilower){
    Nodo nodo;
    while (!filaPriorizada.empty()) {
        if (ilower<mejorCamino) {
            nodo.inivel=nivel++;
        }
        if (nivel==iNumCasas-1) {
            // filaPriorizada.top();
            filaPriorizada.pop();
        }
    }
}

int main()
{
    int iNumCaminos, iDist;
    char cCasa1, cCasa2;
    //Ingresamos los datos de el numero de casas y caminos
    cin>>iNumCasas>>iNumCaminos;

    inicializarMatriz(iNumCasas);
    //Ingresamos las distancias entre las casa
    for(int i=1; i<=iNumCaminos; i++)
    {
        cin>>cCasa1>>cCasa2>>iDist;
        iMat[cCasa1 - 65][cCasa2 - 65] = iDist;
        iMat[cCasa2 - 65][cCasa1 - 65] = iDist;
    }
    primerNodo();
    cout <<mejorCamino <<endl;
    return 0;
}
