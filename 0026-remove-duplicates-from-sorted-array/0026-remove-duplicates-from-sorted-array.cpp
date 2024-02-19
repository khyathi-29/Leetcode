class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*set<int> a;
        
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

        }*/
        int i=0;
        for(int j=1;j<nums.size();j++)
        {
            if(nums[i]!=nums[j])
            {   i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
        
    }
};