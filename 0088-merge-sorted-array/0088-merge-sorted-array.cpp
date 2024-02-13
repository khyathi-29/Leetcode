class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     
        vector<int> a;
        int j=0;
        int k=0;
        int i=0;
        
        while(j<m && k<n)
            {
            if(nums1[j]>nums2[k])
            {
                a.push_back(nums2[k]);
                cout<<"2nd "<<nums2[k];
                k=k+1;
            }
            else 
            {
                a.push_back(nums1[j]);
                cout<<"1st "<<nums2[k]<<" ";
                j=j+1;
            }}
        while(j<m)
        {
            a.push_back(nums1[j]);
            cout<<"1st "<<nums1[k]<<" ";
            j=j+1;
        }
        while(k<n)
        {
            a.push_back(nums2[k]);
            cout<<"2nd "<<nums2[k]<<" ";
            k=k+1;
        }
        for(int i=0;i<a.size();i++)
        {
            nums1[i]=a[i];
        }
        
    }
};