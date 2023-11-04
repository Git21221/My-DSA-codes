class Solution {
vector<int> parent, rank;

    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);
        
        if(parent_x == parent_y) return;

        if(rank[parent_x] > rank[parent_y]) parent[parent_y] = parent_x;
        else if(rank[parent_x] < rank[parent_y]) parent[parent_x] = parent_y;
        else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& c) {
        if(c.size() < n - 1) return -1;
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
        for(auto &it : c){
            int x = it[0];
            int y = it[1];
            if(find(x) != find(y)) Union(x, y);
        }
        for(int i = 0; i < n; i++) parent[i] = find(i);
        set<int> s;
        for(auto &it : parent) s.insert(it);
        return s.size() - 1;
    }
};