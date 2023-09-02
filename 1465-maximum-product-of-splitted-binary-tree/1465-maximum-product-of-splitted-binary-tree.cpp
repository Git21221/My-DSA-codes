class Solution {
const long long mod = 1e9 + 7;
vector<int> arr;
private:
    int dfs(TreeNode* root){
        int sum = 0, lsum = 0, rsum = 0;
        if(root -> left) lsum = dfs(root -> left);
        if(root -> right) rsum = dfs(root -> right);
        sum = lsum + rsum + root -> val;
        arr.push_back(sum);
        return sum;
    }
public:
    int maxProduct(TreeNode* root) {
        dfs(root);
        long long total_sum = arr[arr.size() - 1], maxAns = -1e18;
        for(auto it: arr){
            long long num = total_sum - it;
            maxAns = max(maxAns, it*num);
        }
        return (maxAns % mod);
    }
};