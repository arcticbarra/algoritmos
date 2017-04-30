#include <iostream>

using namespace std;

int counter = 0;
int mat[100][100];

int patron(int n, int i, int j) {
    
    n= n/2;
    i= i/n;
    j= j/n;
    
    if(i % 2 == 0 && j % 2 == 0)
        return 1;
    else if(i % 2 == 0 && j % 2 != 0)
        return 2;
    else if(i % 2 != 0 && j % 2 == 0)
        return 3;
    else
        return 4;
}

void triomino(int p,int n,int i,int j,int wx1,int wy1) {
    
    counter++;
    
    if(n==1)
    {
        switch(p)
        {
            case 1:
                mat[i][j+1] = mat[i+1][j] = mat[i+1][j+1] = counter;
                break;
            case 2:
                mat[i][j] = mat[i+1][j] = mat[i+1][j+1] = counter;
                break;
            case 3:
                mat[i][j] = mat[i][j+1] = mat[i+1][j+1] = counter;
                break;
            case 4:
                mat[i][j+1] = mat[i+1][j] = mat[i][j] = counter;
                break;
        }
        return;
    }
    else
    {
        int p1 = 4, p2 = 3, p3 = 2, p4 = 1;
        i = i + n/2;
        j = j + n/2;
        int px1, px2, px3, px4, py1, py2, py3, py4;
        px1 = i;
        py1 = j;
        px2 = i;
        py2 = j + 1;
        px3 = i + 1;
        py3 = j;
        px4 = i + 1;
        py4 = j + 1;
        
        switch(p)
        {
            case 1:
                mat[i][j+1] = mat[i+1][j] = mat[i+1][j+1] = counter;
                p1 = patron((n+1)/2, wx1, wy1);
                px1 = wx1;
                py1 = wy1;
                break;
            case 2:
                mat[i][j] = mat[i+1][j] = mat[i+1][j+1] = counter;
                p2 = patron((n+1)/2, wx1, wy1);
                px2 = wx1;
                py2 = wy1;
                break;
            case 3:
                mat[i][j] = mat[i][j+1] = mat[i+1][j+1] = counter;
                p3 = patron((n+1)/2, wx1, wy1);
                px3 = wx1;
                py3 = wy1;
                break;
            case 4:
                mat[i][j+1] = mat[i+1][j] = mat[i][j] = counter;
                p4 = patron((n+1)/2, wx1, wy1);
                px4 = wx1;
                py4 = wy1;
                break;
        }

        triomino(p1, n/2, i-(n/2), j-(n/2), px1, py1);
        triomino(p2, n/2, i-(n/2), j+1, px2, py2);
        triomino(p3, n/2, i+1, j-(n/2), px3, py3);
        triomino(p4, n/2, i+1, j+1, px4, py4);
    }
}

int main(int argc, char *argv[]) {

    int k, x, y;
    cout << "Ingresa n: ";
    cin >> k;
    cout << endl << "Ingresa x: ";
    cin >> x;
    cout << endl << "Ingresa y: ";
    cin >> y;
    int p = patron(k, x, y);
    
    triomino(p, k-1, 0, 0, x, y);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
    
}
