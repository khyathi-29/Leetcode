class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int leftElements = (n1+n2+1)/2;
        int l1,l2,r1,r2 ;
        int i=0;
        int j= nums1.length;
        while(i<=j){
            int mid1 = (i+j)/2;
            int mid2 = leftElements-mid1;
            l1 = (mid1>0)?nums1[mid1-1]:Integer.MIN_VALUE;
            l2 = (mid2>0)?nums2[mid2-1]:Integer.MIN_VALUE;
            r1 = (mid1<n1)?nums1[mid1]:Integer.MAX_VALUE;
            r2 = (mid2<n2)?nums2[mid2]:Integer.MAX_VALUE;
            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2==1){
                    return Math.max(l1,l2);
                }
                else{
                    return (double)(Math.max(l1,l2)+Math.min(r1,r2))/2;
                }
            }
            else if(l1>r2){
                j = mid1-1;
            }
            else{
                i = mid1+1;
            }
        }
        return 0;
    }
}