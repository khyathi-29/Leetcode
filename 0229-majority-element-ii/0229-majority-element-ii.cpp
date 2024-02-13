class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0;
        int count2=0;
        int e1=INT_MIN,e2=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(count1==0 && e2!=nums[i])
            {
                count1++;
                e1=nums[i];
            }
            else if(count2==0 && e1!=nums[i])
            {
                count2++;
                e2=nums[i];
            }
            else if( e1==nums[i])
            {
                count1++;
            }
            else if( e2==nums[i])
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        vector<int> a;
        count1=0;
        count2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(e1==nums[i])
            count1++;
            else if(e2==nums[i])
            count2++;
        }
        if(count1>nums.size()/3)
        a.push_back(e1);

        if(count2>nums.size()/3)
        a.push_back(e2);

        sort(a.begin(),a.end());
        return a;
    }
};