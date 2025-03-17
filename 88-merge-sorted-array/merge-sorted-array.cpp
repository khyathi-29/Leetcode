class Solution {
public:
  //try arranging elements in reverse order first place largest and next move forward
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=nums1.size()-1;
        while(i>-1 && j>-1 && k>-1)
        {
             if(nums1[i]<=nums2[j])
             {
                nums1[k]=nums2[j];
                j--;
                k--;

             }
             else
             {
                nums1[k]=nums1[i];
                i--;
                k--;

             }
        }
        while(k>-1 && j>-1){
            nums1[k]=nums2[j];
            j--;
            k--;
        }
        /*int l1 = m;
        int l2 = n;
        int j = l2-1;
        int i=0;
        while(i<l1 && j>-1)
        {
            if(nums1[i]<nums2[j])
            {
                int k = nums1[i];
                nums1[i]=nums2[j];
                nums2[j]=k;
                j--;
                i++;
            }
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());*/
    }
};