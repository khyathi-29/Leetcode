class Solution {
public:
    int trap(vector<int>& height) {
        //logic minimum of two max wall on left and right
        int n = height.size();
        int maxLeft = height[0];
        int maxRight = height[n-1];
        int left = 1;
        int right = n-2;
        int trap =0;
        while(left<=right)
        {
            if(maxLeft<=maxRight)
            {
                maxLeft=max(height[left],maxLeft);
                if(height[left]<maxLeft) trap+= maxLeft-height[left];
                left++;
            }
            else
            {
                maxRight=max(height[right],maxRight);
                if(height[right]<maxRight) trap+=maxRight-height[right];
                right--;

            }
        }
        return trap;
    }
};