class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> a;
        int k=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
            {
                k=i;
                break;
            }
        }
        int i=k-1;
        int j=k;
        while(i>=0 && j<nums.size())
        {
            if(nums[i]*nums[i]>nums[j]*nums[j])
            {
                a.push_back(nums[j]*nums[j]);
                j++;
            }
            else
            {
                a.push_back(nums[i]*nums[i]);
                i--;
            }
        }
            while(j<nums.size())
            {
                a.push_back(nums[j]*nums[j]);
                j++;
            }
            while(i>-1)
            {
                a.push_back(nums[i]*nums[i]);
                i--;
            }
        

       return a;
        }
};