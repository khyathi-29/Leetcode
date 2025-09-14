class Solution {
public:
    int trap(vector<int>& height) {
         int n = height.size();
        int maxLeft = height[0];
        int maxRight = height[n-1];
        int l = 1;
        int r = n-2;
        int ans =0;
        while(l<=r)
        {
            if(maxLeft<maxRight)
            {
                if(height[l]>maxLeft) maxLeft = height[l];
                else ans+= maxLeft-height[l];
                l++;
            }
            else{
                 if(height[r]>maxRight) maxRight = height[r];
                 else ans+= maxRight-height[r];
                 r--;
            }
        }
        return ans;
    }
};