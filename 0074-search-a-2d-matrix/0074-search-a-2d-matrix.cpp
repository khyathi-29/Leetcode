class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int c_r = r;
        for(int i=0;i<r;i++)
        {
            if(matrix[i][c-1]>=target)
            {
               c_r=i;
               break;
            }
        }
        if (c_r==r)
        {
            return false;
        }
        int start = 0;
        int end = c-1;
        int mid;
        while(start<=end)
        {
            mid = start + (end-start)/2;
            if(matrix[c_r][mid]==target)
            {
                return true;
            }
            else if(matrix[c_r][mid]>target)
            {
                end = mid-1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return false;
        
    }
};