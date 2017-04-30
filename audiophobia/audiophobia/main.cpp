//
//  main.cpp
//  audiophobia
//
//  Created by Enrique Barragán on 2/23/17.
//  Copyright © 2017 Enrique Barragan. All rights reserved.
//

#include <iostream>

#define INF 99999

using namespace std;

int main(int argc, const char * argv[]) {
    // c is crossings, s is number of streets, q is number of queries
    int cases, c, s, q, c1, c2, d;
    int D[101][101];
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        cin >> c >> s >> q;
        
        // fill matrix fith 0's
        for (int j = 0; j <= c; j++) {
            for (int k = 0; k <= c; k++) {
                D[j][k] = INF;
                D[k][j] = INF;
                if (j == k) {
                     D[j][k] = 0;
                }
            }
        }
        
        // input of pahts
        for (int j = 0; j < s; j++) {
            cin >> c1 >> c2 >> d;
            D[c1][c2] = d;
            D[c2][c1] = d;
        }
        
        // de los maximos el menor
        for (int k = 0; k <= c; k++) {
            for (int l = 0; l <= c; l++) {
                for (int j = 0; j <= c; j++) {
                        int x;
                        x = (D[l][k] > D[k][j]) ? D[l][k] : D[k][j];
                        if (x < D[l][j]) {
                            D[l][j] = x;
                            D[j][j] = x;
                        }
                }
            }
        }
        
        // query solving
        cout << "Case " << i + 1 << ":" << endl;
        for (int j = 0; j < q; j++) {
            cin >> c1 >> c2;
            D[c1][c2] == INF ? cout << "no path" << endl : cout << D[c1][c2] << endl;
        }
        
    }
    
    return 0;
}
