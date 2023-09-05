class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int,int> m; //storing first and last occurance of any number
        int minAns = INT_MAX, n = cards.size();
        for(int i = 0; i < n; i++){
            if(m.find(cards[i]) != m.end()){
                minAns = min(minAns, i - m[cards[i]] + 1);
            }
            m[cards[i]] = i;
        }
        return minAns == INT_MAX ? -1 : minAns;
    }
};