class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        k=k-1;
        vector<int> nums;
        for(int i = 1;i< n+1;i++)
        {
            fact*=i;
            nums.push_back(i);
        }
        fact = fact/n;
        string ans = "";
        while(nums.size()!=0)
        {   
            int target = k/fact;
            k = k%fact;
            ans = ans + to_string(nums[target]);
            nums.erase(nums.begin()+target);
            if(nums.size()!=0) fact = fact/nums.size();
            
        }
        return ans;
    }
};