class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int m = 0;
        for(int i = 2; i < nums.size(); i++) 
        {
            m = max(m,nums[i-2]);
            if(m>nums[i]) return false;
        }
	return true;
        /*long long int local=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
            {
                local++;
            }
        }
        long long int global=mergesort(nums,0,nums.size()-1);
        if(local==global)
        {
        return true;
        }
        else
        {
        return false;
        }*/
        
    }
    int merge(vector<int>& arr,int low,int mid,int high)
{
    int i=low;
    int j=mid+1;
    long long int count =0;
    int k=0;
    vector<long long int>a;

    while(i<=mid && j<=high)
    {
        if(arr[i]>arr[j])
        {
          a.push_back(arr[j]);
          count=count+mid-i+1;
          j++;
        }
        else{
          a.push_back(arr[i]);
          i++;
        }
    }
    while(i<=mid)
    {
        a.push_back(arr[i]);
          i++;
    }
    while(j<=high)
    {
        a.push_back(arr[j]);
          j++;
    }
    k=0;
    for(int i=low;i<=high;i++)
    {
        arr[i]=a[k];
        k++;
    }
    a.clear();
    return count;
} 
int mergesort(vector<int>& arr, int low, int high)
{
    long long int count =0;
    if(low>=high)
    {
        return count;
    }
    int mid = low + ((high-low)/2);
    count+=mergesort(arr,low,mid);
    count+=mergesort(arr,mid+1,high);
    count+=merge(arr,low,mid,high);
    return count;
}
};