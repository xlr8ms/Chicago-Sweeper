class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, int drow[], int dcol[]){
        int m = grid.size();
        int n = grid[0].size();
        vis[row][col] = 1;
        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >=0 && nrow < m && ncol >=0 && ncol < n
            && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow, ncol, vis, grid, drow, dcol);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) cnt++;
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        for(int i=0; i<n; i++){
            //1st row
            if(grid[0][i] == 1)
            dfs(0, i, vis, grid, drow, dcol);
            //last row
            if(grid[m-1][i] == 1)
            dfs(m-1, i, vis, grid, drow, dcol);
        }
        for(int i=0; i<m; i++){
            //1st col
            if(grid[i][0] == 1)
            dfs(i, 0, vis, grid, drow, dcol);
            //last col
            if(grid[i][n-1] == 1)
            dfs(i, n-1, vis, grid, drow, dcol);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j] == 1) cnt--;
            }
        }
        return cnt;
    }
};