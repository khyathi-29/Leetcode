class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
        
    }
    int merge(vector<int>& arr,int low,int mid,int high)
{
    int i=low;
    int j=mid+1;
    int count =0;
    int k=0;
    vector<long long int>a;

    while(i<=mid && j<=high)
    {
        if(arr[i]>arr[j])
        {
          a.push_back(arr[j]);
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
    return count;
} 

int countpairs(vector<int>& arr, int low,int mid, int high)
{
    int count = 0;
     int j = mid+1;
    for(int i=low;i<mid+1;i++)
    {
        while(j<=high && arr[i]>2LL*arr[j] )
        {
            j++;
        }
        count = count + (j-mid-1);
    }
    return count;
}
int mergesort(vector<int>& arr, int low, int high)
{
    int count =0;
    if(low>=high)
    {
        return count;
    }
    int mid = low + ((high-low)/2);
    count+=mergesort(arr,low,mid);
    count+=mergesort(arr,mid+1,high);
    count+=countpairs(arr,low,mid,high);
    count+=merge(arr,low,mid,high);
    return count;
}
};