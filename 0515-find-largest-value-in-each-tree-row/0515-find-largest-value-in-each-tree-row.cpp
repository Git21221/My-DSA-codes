class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        int max = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == NULL){
                ans.push_back(max);
                max = INT_MIN;
                if(q.empty()) break;
                else q.push(NULL);
            }
            else{
                if(curr -> val > max) max = curr -> val;
                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
            }
        }
        return ans;
    }
};