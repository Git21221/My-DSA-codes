class Solution {
vector<int> parent, rank;
private:
    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);
        
        if(parent_x == parent_y) return;

        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }
        else if(rank[parent_x] < rank[parent_y]){
            parent[parent_x] = parent_y;
        }
        else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        for(auto &it : edges){
            int x = it[0];
            int y = it[1];
            if(find(x) != find(y)) Union(x, y);
        }
        for(int i = 0; i < n; i++) parent[i] = find(i);
        long long ans = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[parent[i]]++;
        }
        for(auto &it : mp){
            long long size = it.second;
            ans += (size) * (n - size);
            n -= size;
        }
        return ans;
    }
};