class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int leftElements = (n1+n2+1)/2;
        int l1 , r1, l2, r2;
        int i=0;
        int j = nums1.length;
        //Search from 0 to n1 (not n1-1) because you can also cut at the 
        //beginning or end of the array.
        while(i<=j)
        {
            int mid1 = i + (j-i)/2;
            int mid2 = leftElements - mid1;
            l1 = (mid1==0)?Integer.MIN_VALUE:nums1[mid1-1];
            r1 = (mid1==n1)?Integer.MAX_VALUE:nums1[mid1];
            l2 = (mid2==0)?Integer.MIN_VALUE:nums2[mid2-1];
            r2 = (mid2==n2)?Integer.MAX_VALUE:nums2[mid2];
            if(l1>r2){
                j = mid1-1;
            }
            else if(l2>r1){
                i = mid1 + 1;
            }
            else{
                if((n1+n2)%2==1) return (double) Math.max(l1,l2);
                else {
                    return (double)(Math.max(l1,l2)+Math.min(r1,r2))/2;
                }
            }

        }
        return -1.00;
        
    }
}