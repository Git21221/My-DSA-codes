class Solution {
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& vis, int node, int color){
        vis[node] = color;
        for(auto it : graph[node]){
            if(vis[it] == -1){
                if(dfs(graph, vis, it, !color) == false) return false;
            }
            else if(vis[it] == color) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        for(int i = 0; i < n; i++){
            if(vis[i] == -1){
                if(dfs(graph, vis, i, 0) == false) return false; 
            }
        }
        return true;
    }
};