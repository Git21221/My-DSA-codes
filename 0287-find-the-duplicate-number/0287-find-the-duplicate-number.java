class Solution {
    public int findDuplicate(int[] nums) {
        int n = nums.length;
        int i = 0;
        while(i < n){
            if(nums[i] != i + 1){
                int crt = nums[i] - 1;
                if(nums[i] != nums[crt]){
                    swap(nums, i, crt);
                }
                else
                    return nums[i];
            }
            else
                i++;
        }
        return -1;
    }
    void swap(int[] nums, int i, int crt){
        int temp = nums[i];
        nums[i] = nums[crt];
        nums[crt] = temp;
    }
}