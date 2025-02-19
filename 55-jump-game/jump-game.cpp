class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        vector<bool> possible(n,false);
        possible[0]=true;
        for(int i=0;i<n;i++)
        {
            int k = nums[i];
            if(possible[i]==true){
            for(int j = i+1; j < i+k+1;j++)
            {
                if(j<n) {
                    possible[j] = true;
                    //cout<<i<<endl;
                }
            }
            }
            
        }
        return possible[n-1];
        
    }
};