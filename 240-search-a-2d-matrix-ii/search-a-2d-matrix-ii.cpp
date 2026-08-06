class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return search(matrix, matrix.size(), matrix[0].size(), target);
    }
    bool search(vector<vector<int>>& mat, int n, int m, int key) {
    int row = 0, col = m-1;
    while(row<n && col >= 0) {
        if(mat[row][col] == key) return 1;
        else if(mat[row][col] > key) col--;
        else row++;
    }
    return 0;
    }
};