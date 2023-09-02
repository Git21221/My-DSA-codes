class Solution {
private:
    int dfs(TreeNode* root, int maxAns) {
        if(root == NULL) return 0;
        int ans = root -> val >= maxAns ? 1 : 0;
        ans += (dfs(root -> left, max(maxAns, root -> val)) + dfs(root -> right, max(maxAns, root -> val)));
        return ans;
    }
public:
    int goodNodes(TreeNode* root) {
        int maxAns = -1e9;
        return dfs(root, maxAns);
    }
};