class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i =0;
        vector<int> ans;
        while(i<nums.size())
        {
            int pos = nums[i]-1;
            if(nums[pos]!=nums[i])
            {
                swap(pos,i,nums);
            }
            else i++;
        }
        for(i=0 ; i<nums.size(); i++)
        {
            if(nums[i]!=i+1) ans.push_back(nums[i]);
        }
        return ans;
    }
    void swap(int i,int j, vector<int>& a){
        int k = a[i];
        a[i]=a[j];
        a[j]=k;
        return;
    }
};