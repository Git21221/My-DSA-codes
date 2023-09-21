class Solution {
public:
    float findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), i, j, mergedArray[10000];
        for(i = 0 ; i < m; i++)
            mergedArray[i]=nums1[i];
        for(i = 0, j = m ; j< m + n && i < n; i++ , j++)
            mergedArray[j]=nums2[i];
       sort(mergedArray,mergedArray+m+n);
        int c = m + n;  
    if(c % 2 == 0)
        return (float) (mergedArray[(c / 2) - 1] + mergedArray[(c / 2)]) / 2;
    else
        return mergedArray[c / 2];
    }
};