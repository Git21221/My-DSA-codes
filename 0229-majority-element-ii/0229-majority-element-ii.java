class Solution {
    public List<Integer> majorityElement(int[] nums) {
        HashMap<Integer, Integer> hm = new HashMap<>();
        ArrayList<Integer> al = new ArrayList<>();
        for(int num : nums){
            if(hm.containsKey(num)){
                hm.put(num, hm.get(num) + 1);
            }
            else
                hm.put(num, 1);
        }
        Set<Integer> keySet = hm.keySet();
        for(Integer key : keySet){
            if(hm.get(key) > nums.length / 3)
                al.add(key);
        }
        return al;
    }
}