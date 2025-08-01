class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int n = (n1+n2+1)/2;
        int low = 0;
        int high = n1;
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;
        while(low<=high)
        {
            int mid1 = low + (high-low)/2;
            int mid2 = n - mid1;
            l1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
            l2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
            r1 = (mid1 < n1) ? nums1[mid1] : INT_MAX;
            r2 = (mid2 < n2) ? nums2[mid2] : INT_MAX;
            if(l1 <= r2 && l2 <= r1){
                if((n1+n2)%2==1){
                    return (double)max(l1,l2);
                }
                else{
                    return (double)(max(l1,l2)+min(r1,r2))/2.00;
                }
            }
            else if(l1>r2)
            {
                 high = mid1-1;
            }
            else {
                low = mid1+1;
            }




        }

        return -1;
        
    }
};