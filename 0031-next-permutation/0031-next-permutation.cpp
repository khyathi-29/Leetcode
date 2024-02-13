class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      //1 2 5 4 3 2 1;
      //5 4 3 2 1
      int pivot=-1;
      int n = nums.size();
      if(n==1)
      {
          return;
      }
      for(int i=n-2;i>=0;i--)
      {
          if(nums[i]<nums[i+1])
          {
              pivot = i;
              //cout<<pivot;
              break;
          }
       } 
      if(pivot==-1)
      {
          sort(nums.begin(),nums.end());
          return;
      }

       for(int i=n-1;i>-1;i--)
      {
          if(nums[i]>nums[pivot])
          {
              int temp = nums[pivot];
              nums[pivot]=nums[i];
              nums[i]=temp;
              break;
          }
      }
      for(int i=0;i<n;i++)
      {
          cout<<nums[i]<<" ";
      }
      cout<<endl;
      sort(nums.begin()+pivot+1,nums.end());
      for(int i=0;i<n;i++)
      {
          cout<<nums[i]<<" ";
      }
      return;
    }
};