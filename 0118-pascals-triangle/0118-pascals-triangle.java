class Solution {
    public List<List<Integer>> generate(int n) {
        List<List<Integer>> arr = new ArrayList<>();
        ArrayList<Integer> al = new ArrayList<>();
        ArrayList<Integer> temp = new ArrayList<>();
        for(int i = 0; i < n; i++){
        al = new ArrayList<Integer>();
            for(int j = 0; j <= i; ++j){
                if(j == 0 || j == i)
                    al.add(1);
                else
                    al.add(temp.get(j - 1) + temp.get(j));
            }
            temp = al;
            arr.add(al);
        }
        return arr;
    }
}