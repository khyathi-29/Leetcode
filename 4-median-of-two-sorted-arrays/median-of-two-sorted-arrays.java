class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int mid = (n1+n2+1)/2;
        int l1 = Integer.MIN_VALUE;
        int h1 = Integer.MAX_VALUE;
        int l2 = l1;
        int h2 = h1;
        int high = n1;
        int low = 0;
        while(low<=high)
        {
            int mid1 = low+(high-low)/2;
            int mid2 = mid-mid1;
          
            l1 = (mid1>0)? nums1[mid1-1]:  Integer.MIN_VALUE;
            l2 = (mid2>0)? nums2[mid2-1]:  Integer.MIN_VALUE;
            h1 = (mid1<n1)? nums1[mid1]:  Integer.MAX_VALUE;
            h2 = (mid2<n2)? nums2[mid2]:  Integer.MAX_VALUE;
           if(l1<=h2 && l2<=h1)
           {
             if((n1+n2)%2==1) return (double)Math.max(l1,l2);
             else return  (double)(Math.max(l1,l2)+Math.min(h1,h2))/2.00;
           }
           else if(l1>h2)
           {
              high = mid1-1;
           }
           else{
             low = mid1+1;
           }
        }
        return -1;
    }
}