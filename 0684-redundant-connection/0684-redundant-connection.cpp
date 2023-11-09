class Solution {
    vector<int> parent, rank;
    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return;
        if(rank[px] > rank[py]) {
            parent[py] = px;
        } else if(rank[px] < rank[py]) {
            parent[px] = py;
        } else {
            parent[px] = py;
            rank[py]++;
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans(2, 0);
        int n = edges.size();
        parent.resize(n+1, 0);
        rank.resize(n+1);
        for(int i = 1; i <= n; i++) parent[i] = i;
        for(int i = 0; i < n; i++){
            int u = edges[i][0], v = edges[i][1];
            int pu = find(u), pv = find(v);
            if(pu == pv){
                ans[0] = u;
                ans[1] = v;
            }
            else{
                Union(u, v);
            }
        }
        return ans;
    }
};