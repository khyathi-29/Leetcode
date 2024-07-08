class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0,count2=0;
        int element1=INT_MIN,element2=INT_MIN;
        for(int n: nums)
        {
            if(count1==0 && n!=element2)
            {
                element1 = n;
                count1++;
            }
            else if(count2==0 && n!=element1)
            {
                element2 =n;
                count2++;
            }
            else if (n==element1) count1++;
            else if(n==element2) count2++;
            else
            {
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        int k = nums.size()/3;
        for( int n: nums)
        {
            if(n==element1 && element1!=INT_MIN) count1++;
            if(n==element2 && element2!=INT_MIN) count2++;
        }
        vector<int> ans;
        if(count1>k) ans.push_back(element1);
        if(count2>k) ans.push_back(element2);
        return ans;
    
    }
};