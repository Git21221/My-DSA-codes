class Solution {
private:
    void dfs(vector<string> &ans, unordered_map<string, multiset<string>> &adj, string s){
        while(adj[s].size()){
            string str = *adj[s].begin();
            adj[s].erase(adj[s].begin());
            dfs(ans, adj, str);
        }
        ans.push_back(s);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ans;
        unordered_map<string, multiset<string>> adj;
        for(auto it : tickets){
            string u = it[0];
            string v = it[1];
            adj[u].insert(v);
        }
        dfs(ans, adj, "JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};