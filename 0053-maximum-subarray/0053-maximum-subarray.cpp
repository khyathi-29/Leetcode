class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long int maxsum=INT_MIN;
        long long int c_sum = 0;
        int start=-1,end=-1,s=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(c_sum==0)s=i;
            c_sum = c_sum + nums[i];
            
            if(maxsum<c_sum)
            {
                maxsum=c_sum;
                start=s;
                end=i;
            }
            if(c_sum<0)
            {
                c_sum=0;
            }
        }
        cout<<start<<" "<<end;
        return maxsum;
    }
};