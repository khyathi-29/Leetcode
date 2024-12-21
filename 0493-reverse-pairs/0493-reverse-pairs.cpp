class Solution {
public:
    void merge(vector<int>& nums, int low,int mid, int high)
    {
        int i=low;
        int j=mid+1;
        vector<int> a;
        while(i<=mid && j<=high)
        {
         if(nums[i]>nums[j])
         {
            a.push_back(nums[j]);
            j++;
         }
         else
         {
            a.push_back(nums[i]);
            i++;
         }
        }
        while(i<=mid)
        {
             a.push_back(nums[i]);
            i++;
        }
        while(j<=high)
        {
             a.push_back(nums[j]);
            j++;
        }
        int k=0;
        for(int i=low;i<=high;i++)
        {
            nums[i]=a[k];
            k++;
        }
    }
    int reversepairs(vector<int>& nums, int low,int mid, int high)
    {
        int i=low;
        int j = mid+1;
        int count=0;
        for(int i=low;i<=mid;i++)
        {
            while(j<=high && nums[i]>(long long)2*nums[j])
            {
                j++;
            }
            count+=j-(mid+1);
        }
        return count;
    }
    int mergeSort(vector<int>& nums, int low, int high){
        int count=0;
        if(low>=high) return count;
        int mid = low + (high-low)/2;
        count+=mergeSort(nums,low,mid);
        count+=mergeSort(nums,mid+1,high);
        count+=reversepairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return count;
        }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
        
    }
};