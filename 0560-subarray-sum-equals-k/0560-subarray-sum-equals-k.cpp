class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_multiset<int> a;
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            sum = sum+nums[i];
            if(sum==k)
            {
                count++;
            }
            if(a.find(sum-k)!=a.end())
            {
                count+=a.count(*a.find(sum-k));
            }
            a.insert(sum);
        }
        
        return count;
    }
};