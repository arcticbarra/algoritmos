//
//  main.cpp
//  Cutting Sticks
//
//  Created by Enrique Barragán on 3/5/17.
//  Copyright © 2017 Enrique Barragan. All rights reserved.
//

#include <iostream>
#include <limits.h>

using namespace std;

int main(int argc, const char * argv[]) {

    int length, cuts, price;
    
    cin >> length >> cuts;
    
    while (length != 0) {
        
        int prices[51], A[51][51]; // n <= 50
        prices[0] = 0;
        
        for (int i = 1; i <= cuts; i++) { // Arreglo de precios
            cin >> price;
            prices[i] = price;
        }
        
        cuts++;
        prices[cuts] = length;
        
        // Cut the sticks
        
        for (int j = 1; j <= cuts; j++) {
            for (int i = j - 1; i >= 0; i--) {
                if (i + 1 == j){ // Diagonal
                    A[i][j] = 0;
                } else {
                    A[i][j] = INT_MAX;
                    for (int k = i + 1; k < j; k++) {
                        if (A[i][k] + A[k][j] < A[i][j]) { // Sacar el mínimo
                            A[i][j] = A[i][k] + A[k][j];
                        }
                    }
                    A[i][j] += prices[j] - prices[i];
                }
            }
        }
        
        // End of cut the sticks
        
        cout << "The minimum cutting is " << A[0][cuts] << "." << endl;
        
        cin >> length >> cuts;
    }
    
    return 0;
}
