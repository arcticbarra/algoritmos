#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 99999

int main() {

    int n,m,x,y,r;
    cin >> n >> m;
    int D[n+1][n+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            D[i][j] = INF;
            if (i == j) {
                D[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> x >> y >> r;
        D[x][y] = r;
    }

    for (int k = 0; k <= n; k++) {
      for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (D[i][k] + D[k][j] < D[i][j]) {
                D[i][j] = D[i][k] + D[k][j];
            }
        }
      }
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> x >> y;
        D[x][y] == INF ? cout << -1 << endl : cout << D[x][y] << endl;
    }

    return 0;
}
