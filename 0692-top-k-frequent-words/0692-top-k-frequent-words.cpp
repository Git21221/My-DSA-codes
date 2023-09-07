class Solution {
private:
    static bool cmp(pair<int, string> &a, pair<int, string> &b){
        if(a.first == b.first){
            int val = a.second.compare(b.second);
            if(val < 0) return a.first;
            else b.first;
        }
        return a.first > b.first; 
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string, int> m;
        for(auto i : words){
            m[i]++;
        }
        vector<pair<int, string>>temp;
        for(auto it: m){
            temp.push_back({it.second, it.first});
        }
        sort(temp.begin(), temp.end(), cmp);
        vector<string> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(temp[i].second);
        }
        return ans;
    }
};