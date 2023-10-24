class Solution {
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> al = new ArrayList<>();
        bfs(root, al);
        return al;
    }
    void bfs(TreeNode root, List<Integer> al){
        int max = Integer.MIN_VALUE;
        if(root == null)
            return;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        q.add(null);
        while(!q.isEmpty()){
            TreeNode curr = q.remove();
            if(curr == null){
                al.add(max);
                max = Integer.MIN_VALUE;
                if(q.isEmpty())
                    break;
                else
                    q.add(null);
            }
            else{
                if(curr.val > max)
                    max = curr.val;
                if(curr.left != null)
                    q.add(curr.left);
                if(curr.right != null)
                    q.add(curr.right);
            }
        }
    }
}