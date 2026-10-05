class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, int drow[], int dcol[], vector<vector<char>>& board){
        int m = board.size();
        int n = board[0].size();
        vis[row][col] = 1;
        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >=0 && nrow < m && ncol >=0 && ncol < n
            && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                dfs(nrow, ncol, vis, drow, dcol, board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        vector<vector<int>> vis(m, vector<int>(n,0));
        for(int j=0; j<n; j++){
            //1st row
            if(board[0][j] == 'O')
            dfs(0, j, vis, drow, dcol, board);
            //last row
            if(board[m-1][j] == 'O')
            dfs(m-1, j, vis, drow, dcol, board);
        }
        for(int i=0; i<m; i++){
             //1st col
            if(board[i][0] == 'O')
            dfs(i, 0, vis, drow, dcol, board);
            //last col
            if(board[i][n-1] == 'O')
            dfs(i, n-1, vis, drow, dcol, board);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j] == 0 && board[i][j] == 'O')
                board[i][j] = 'X';
            }
        }
    }
};