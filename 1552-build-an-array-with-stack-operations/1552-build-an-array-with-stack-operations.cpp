class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> v;
        int m = target.size(), j = 1;
        for(int i = 0; i < m; i++){
            while(target[i] != j){
                v.push_back("Push");
                v.push_back("Pop");
                j++;
            }
            if(target[i] == j){
                v.push_back("Push");
                j++;
            }
        }
        return v;
    }
};