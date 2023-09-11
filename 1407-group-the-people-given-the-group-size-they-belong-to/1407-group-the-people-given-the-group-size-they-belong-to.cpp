class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        unordered_map<int, vector<int>> m;
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            m[groupSizes[i]].push_back(i);
            if(m[groupSizes[i]].size() == groupSizes[i]){
                ans.push_back(m[groupSizes[i]]);
                m[groupSizes[i]] = {};
            }
        }
        return ans;
    }
};