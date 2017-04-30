//
//  main.cpp
//  Median
//
//  Created by Enrique Barragán González A01370878 and Aldo Cervantes Barbosa A01039261 on 3/14/17.
//  Copyright © 2017 Enrique Barragan. All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;

int max(int a, int b) {
    return a>b ? a: b;
}

int min(int a, int b) {
    return a>b ? b: a;
}

int main(int argc, const char * argv[]) {
    
    int t, n = 0;
    cin >> t;
    for (int k = 0; k < t; k++) {
        cin >> n;
        int a[n];
        int b[n];
        for (int m = 0; m < n; m++) {
            cin >> a[m];
        }
        for (int m = 0; m < n; m++) {
            cin >> b[m];
        }
        
        // median search
        int imin,imax,mitad;
        imin = 0;
        imax = n;
        mitad = (n+n+1)/2;
        while (imin<=imax) {
            int max_izq, min_der;
            int i = (imin+imax)/2;
            int j = mitad-i;
            if (i<n && b[j-1]>a[i]) {
                imin=i+1;
            } else if (i > 0 && a[i-1] > b[j]){
                imax=i-1;
            } else {
                if (i==0)
                    max_izq = b[j-1];
                else if (j==0)
                    max_izq = a[i-1];
                else
                    max_izq = max(a[i-1], b[j-1]);
                if ((n+n) % 2 == 1) {
                    cout << "Median case " << k+1 << ": " << setprecision(2) << fixed << max_izq;
                    break;
                }
                if (i == n)
                    min_der = b[j];
                else if(j==n)
                    min_der = a[i];
                else
                    min_der = min(a[i],b[j]);
                
                cout << "Median case " << k+1 << ": " << setprecision (2) << fixed << (max_izq + min_der) / 2.0 << endl;
                break;
            }
        }
    }

    return 0;
}
