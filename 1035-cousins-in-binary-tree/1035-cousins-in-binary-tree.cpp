class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int storingParentx = -1, storingLevelx = -1, storingParenty = -1, storingLevely = -1;
        queue<tuple<TreeNode*, int, int>> q; //node, parent, level
        q.push({root, -1, 0});
        while(!q.empty()){
            tuple<TreeNode*, int, int> t = q.front();
            q.pop();
            TreeNode* curr = get<0>(t);
            int parent = get<1>(t);
            int level = get<2>(t);
            if(curr -> val == x){
                storingParentx = parent;
                storingLevelx = level;
            }
            if(curr -> val == y){
                storingParenty = parent;
                storingLevely = level;
            }
            if(curr -> left) q.push({curr -> left, curr -> val, level + 1});
            if(curr -> right) q.push({curr -> right, curr -> val, level + 1});
        }
        if(storingParentx == storingParenty) return false;
        else{
            if(storingLevelx == storingLevely) return true;
            else return false;
        }
        return false;
    }
};