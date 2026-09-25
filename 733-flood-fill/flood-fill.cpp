class Solution {
private:
    void bfs(int sr, int sc, int color, vector<vector<int>>& vis, vector<vector<int>>& image){
        int m = image.size();
        int n = image[0].size();
        vis[sr][sc] = 1;
        int c = image[sr][sc];
        image[sr][sc] = color;
        queue<pair<int,int>> q;
        q.push({sr, sc});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int drow[] = {-1,0,1,0};
            int dcol[] = {0,1,0,-1};
            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n
                && image[nrow][ncol] == c && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    image[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        bfs(sr, sc, color, vis, image);
        return image;
    }
};