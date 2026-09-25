class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int>& va){
        va[node] = 1;
        for(auto it:adj[node]){
            if(!va[it]){
                dfs(it, adj, va);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> va(n, 0);
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(!va[i]){
                cnt++;
                dfs(i, adj, va);
            }
        }
        return cnt;
    }
};