//
//  main.cpp
//  security
//
//  Created by Enrique Barragán on 2/11/17.
//  Copyright © 2017 Enrique Barragan. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int n,m;
    string c;
    cin >> n >> m;
    char mat[n][m];
    
    // Considerando que la ciudad nunca estará al borde del tablero, es decir, siempre estará rodeada por 0's
    
    for (int i =0; i < n; i++) {
        cin >> c;
        for (int j = 0; j < m; j++) {
            mat[i][j] = c[j];
            if (c[j] == '*' && mat[i-1][j] == '0') {
                mat[i-1][j] = '=';
            }
            if (c[j] == '*' && mat[i][j-1] == '0') {
                mat[i][j-1] = '=';
            }
            if (c[j] == '0' && mat[i][j-1] == '*') {
                mat[i][j] = '=';
            }
            if (c[j] == '0' && mat[i-1][j] == '*') {
                mat[i][j] = '=';
            }
            if (c[j] == '*' && mat[i-1][j] == '=' && mat[i][j-1] == '=') {
                mat[i-1][j-1] = '=';
            }
            if (c[j] == '*' && mat[i-1][j] == '=' && mat[i-1][j+1] == '0') {
                mat[i-1][j+1] = '=';
            }
            if (c[j] == '0' && mat[i-1][j] == '=' && mat[i-1][j+1] == '*') {
                mat[i][j] = '=';
            }
            if (c[j] == '0' && mat[i-1][j] == '=' && mat[i][j-1] == '=' && mat[i-1][j-1] == '*') {
                mat[i][j] = '=';
            }
        }
    }
    
    for (int i =0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
