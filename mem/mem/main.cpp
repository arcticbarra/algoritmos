//
//  main.cpp
//  Multiplicacion Encadenada de Matrices
//
//  Created by Enrique Barragán on 3/25/17.
//  Copyright © 2017 Enrique Barragan. All rights reserved.
//

#include <iostream>
#include <limits.h>

using namespace std;

string ans = "";

void imprimirOrden(int i, int j, int *ordenMatrices, char &letra, int n) {
    if (i == j) {
        ans += "(";
        ans+= letra;
        ans+= ")";
        letra++;
        return;
    }
    ans += "(";
    // *((ordenMatrices+i*n)+j) es lo mismo que ordenMatrices[i][j]
    // http://www.cplusplus.com/forum/beginner/73432/ de acá lo vi
    imprimirOrden(i, *((ordenMatrices + i * n) + j), ordenMatrices, letra, n);
    imprimirOrden(*((ordenMatrices + i * n) + j) + 1, j, ordenMatrices, letra, n);
    ans+= ")";
}

int main(int argc, const char * argv[]) {
    
    int n,minimo;
    cin >> n;
    int d[n+1];
    int ordenMatrices[n][n];
    
    for (int i = 0; i <= n; i++){
        cin >> d[i];
    }
    
    int D[10][10];
    for (int i=1; i<=n; i++)
        D[i][i] = 0;
    
    for (int diag = 1; diag <= n-1; diag++) {
        for (int i = 1; i <= n-diag; i++) {
            int j = i + diag;
            // Minimo
            D[i][j] = INT_MAX;
            for (int k=i; k<=j-1; k++)
            {
                minimo = D[i][k] + D[k+1][j] + d[i-1]*d[k]*d[j];
                if (minimo < D[i][j]) {
                    D[i][j] = minimo;
                    ordenMatrices[i][j] = k;
                }
            }
        }
    }
    
    if (n == 2) { // Sin esto me imprime ((A)x(B)
        cout << "((A)x(B))" << endl;
    } else {
        char letra = 'A';
        // El minimo de multiplicaciones se encuentra en D[1][n]
        imprimirOrden(1, n, (int *)ordenMatrices, letra, n);
        // Imprimir 'x'
        for (int i = 0; i < ans.length()-1; i++) {
            cout << ans[i];
            if (ans[i] == ')' && ans[i+1] == '(') {
                cout << 'x';
            }
        }
        cout <<endl;
    }
    
    return 0;
}
