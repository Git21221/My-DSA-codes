class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        vector<char> e1, e2, o1, o2;
        for(int i = 0; i < n; i++){
            if((i & 1) == 0){
                e1.push_back(s1[i]);
                e2.push_back(s2[i]);
            }
            else{
                o1.push_back(s1[i]);
                o2.push_back(s2[i]);
            }
        }
        sort(begin(e1), end(e1));
        sort(begin(e2), end(e2));
        sort(begin(o1), end(o1));
        sort(begin(o2), end(o2));
        return (e1 == e2) && (o1 == o2);
    }
};