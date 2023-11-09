class Solution {
const int mod = 1e9 + 7;
int fact(int n)
{
    int res = 0, i;
    for (i = 1; i <= n; i++)
        (res += i) %= mod;
    return res;
}
public:
    int countHomogenous(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int l = 0, r = 0, n = s.size(), ans = 0;
        while(r <= n){
            if(s[l] == s[r]) r++;
            else{
                int size = r - l;
                ans += fact(size);
                l = r;
            }
        }
        if(r == n && l == 0) ans += fact(r - l);
        return ans % mod;
    }
};