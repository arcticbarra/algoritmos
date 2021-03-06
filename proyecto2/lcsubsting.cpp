// Enrique Barragán A01370878
// Alan Velasco A01113373
#include<iostream>
#include<string.h>
using namespace std;

int findLCS(string X, string Y, int m, int n)
{
    int matrix[m+1][n+1];
    int result = 0;

    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                matrix[i][j] = 0;

            else if (X[i-1] == Y[j-1])
            {
                matrix[i][j] = matrix[i-1][j-1] + 1;
                result = max(result, matrix[i][j]);
            }
            else matrix[i][j] = 0;
        }
    }
    return result;
}

int main()
{
    int t;
    string a,b;
    cin >> t;
    for (int i = 0; i < t; i++) {
      cin >> a >> b;
      int m = a.length();
      int n = b.length();
      cout << "Case " << i+1 << ": "
           << findLCS(a, b, m, n) << endl;
    }
    return 0;
}
