class Solution {
public:
    int trap(vector<int>& height) {
        int max_left=0;
        int max_right=0;
        vector<int> a;
        vector<int> b(height.size());
        for(int i=0;i<height.size();i++)
        {
            max_left = max(height[i],max_left);
            a.push_back(max_left);     
        }
        for(int i=height.size()-1;i>-1;i--)
        {
            max_right = max(height[i],max_right);
            b[i]=max_right; 
        }
        int count = 0;
        for(int i=0;i<height.size();i++)
        {
            int k = min(a[i],b[i])-height[i];
            if(k>0)
            {
                count+=k;
            }
        }
        return count;
    }
};