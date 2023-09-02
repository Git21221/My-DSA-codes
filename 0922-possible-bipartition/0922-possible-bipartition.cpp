class Solution {
private:
    bool dfs(vector<int> adj[], vector<int>& vis, int node, int color){
        vis[node] = color;
        for(auto it : adj[node]){
            if(vis[it] == -1){
                if(dfs(adj, vis, it, !color) == false) return false;
            }
            else if(vis[it] == color) return false;
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n];
        for(int i = 0; i < dislikes.size(); i++){
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
        vector<int> vis(n, -1);
        for(int i = 0; i < n; i++){
            if(vis[i] == -1){
                if(dfs(adj, vis, i, 0) == false) return false;
            }
        }
        return true;
    }
};