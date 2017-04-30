// Enrique Barragán A01370878
// Alan Velasco A01113373
#include <iostream>
using namespace std;

int tren1[1001],tren2[1001],orden[2001],n,m,t;
int DP[1001][1001];
bool posible;

void matriz(int i,int j,int k){
    if(posible) {
				return;
		}
    if (DP[i][j]==1)
			return;
    if(k==n+m){
	    posible=true;
	    return;
    }
    if(i<n && tren1[i]==orden[k]) {
			matriz(i+1, j, k+1);
		}

    if(j<m && tren2[j]==orden[k]) {
			matriz(i,j+1,k+1);
		}
    DP[i][j]=1;
}

int main(){

    int i,j;
    while(cin>>n>>m){

        if(n==0 && m==0) {
					break;
				}

        for(i=0; i<n; i++) {
            cin>>tren1[i];
				}

        for(i=0; i<m; i++) {
            cin>>tren2[i];
				}
        for(i=0; i<n+m; i++) {
            cin>>orden[i];
				}

        posible = false;
				for (i=0;i<=n;i++) {
					for (j=0;j<=m;j++) {
        		DP[i][j] = 0;
					}
				}
        matriz(0,0,0);

				if (posible) {
					cout<<("possible")<<endl;
				} else {
					cout<<("not possible")<<endl;
				}

    }
    return 0;
}
