class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> a;
        
        for(int i=0; i< nums.size();i++)
        {
           a.insert(nums[i]);
           //cout<<" nums"<<nums[i];
        }
        int k=0;
        for( auto i = a.begin();i!=a.end();i++)
        {
            nums[k]=*i;
            k=k+1;

        }
        return k;
        
    }
};