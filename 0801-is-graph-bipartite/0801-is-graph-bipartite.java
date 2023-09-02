class Solution {
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] color = new int[n];
        Arrays.fill(color, -1);
        for(int i = 0; i < n; i++){
            Queue<Integer> q = new LinkedList<>();
            if(color[i] != -1) continue;
            q.offer(i);
            while(!q.isEmpty()){
                int curr = q.poll();
                for(int it : graph[curr]){
                    if(color[it] == -1){
                        color[it] = 1 - color[curr];
                        q.offer(it);
                    }
                    else if(color[it] == color[curr]) return false;
                }
            }
        }
        return true;
    }
}