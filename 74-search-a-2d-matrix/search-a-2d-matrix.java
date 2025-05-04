class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int row_size = matrix.length;
        int col_size = matrix[0].length;
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
    }
}