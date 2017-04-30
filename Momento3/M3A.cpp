class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty()) {
        return 0;
    }
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> aux(m + 1, 0);
    int squareSize = 0;
    int pre = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 1; i <= m; i++) {
            int temp = aux[i];
            if (matrix[i - 1][j] == '1') {
                aux[i] = min(aux[i], min(aux[i - 1], pre)) + 1;
                squareSize = max(squareSize, aux[i]);
            }
            else {
                aux[i] = 0;
            }
            pre = temp;
        }
    }
    return squareSize * squareSize;
}
};
