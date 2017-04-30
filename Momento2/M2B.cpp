class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if ( matrix.empty() || matrix[0].size() == 0) {
            return false;
        }
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] <= target)
                if (binary_search(matrix[i].begin(), matrix[i].end(), target)) {
                    return true;
                }
            } else {
                return false;
            }
        }
        return false;
    }
};
