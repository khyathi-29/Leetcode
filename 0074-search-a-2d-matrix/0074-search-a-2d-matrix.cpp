class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       //method 1
        int row_size = matrix.size();
        int col_size = matrix[0].size();
        int low = 0;
        int high = row_size*col_size-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int c_r=mid/col_size;
            int c_c=mid%col_size;
            if(matrix[c_r][c_c]==target)
            {
                return true;
            }
            else if(matrix[c_r][c_c]>target)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return false;
        /* int row_size = matrix.size();
        int col_size = matrix[0].size();
        int low = 0;
        int high = row_size-1;
        int mid1;
        while(low<=high)
        {
            mid1 = low + ((high-low)/2);
            if(matrix[mid1][0]==target)
            {
                return true;
            }
            else if(matrix[mid1][0]>target)
            {
                high = mid1-1;
            }
            else
            {
                low = mid1+1;
            }
        }
        mid1 = high;
        if(high<0)return false;
        low =0;
        high = matrix[mid1].size()-1;
        while(low<=high)
        {
            int mid2 = low + ((high-low)/2);
            if(matrix[mid1][mid2]==target)
            {
                return true;
            }
            else if(matrix[mid1][mid2]>target)
            {
                high = mid2-1;
            }
            else
            {
                low = mid2+1;
            }
        }
        return false;*/
        //method 2 
    }
};