class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(n > m) return false;
        vector<int> freq1(26, 0), freq2(26, 0);
        for(auto character : s1){
            freq1[character - 'a']++;
        }
        for(int i = 0; i < n; i++){
            freq2[s2[i] - 'a']++;
        }
        if(equal(freq1.begin(), freq1.end(), freq2.begin(), freq2.end())) return true;
        for(int i = n; i < m; i++){
            freq2[s2[i] - 'a']++;
            freq2[s2[i - n] - 'a']--;
            if(equal(freq1.begin(), freq1.end(), freq2.begin(), freq2.end())) return true;
        }
        return false;
    }
};