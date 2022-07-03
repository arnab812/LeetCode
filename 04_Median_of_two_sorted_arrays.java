class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
       int[] ans = merge(nums1,nums2,nums1.length,nums2.length);
          int len= ans.length;
        double val=0;
        int mid= len/2;
        if(len%2!=0){
            return ans[mid];
        }
       val= ans[mid-1]+ans[mid];
            return val/2;
       
    }
    
    public int[] merge(int arr1[], int arr2[], int n, int m) {
        // code here
        int i=0;
        int j=0;
        int k=0;
        int[] res= new int[n+m];
        while(i<n && j<m){
            if (arr1[i] >arr2[j]){
                res[k]= arr2[j];
                j++;
            }
            else{
                res[k]= arr1[i];
                i++;
            }
            k++;
        }
        while (i<n){
            res[k]= arr1[i];
            i++;
            k++;
        }
        while (j<m){
            res[k]= arr2[j];
            j++;
            k++;
        }
       
        return res;
    }
}
