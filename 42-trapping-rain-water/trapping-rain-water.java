class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int leftHeight = height[0];
        int rightHeight = height[n-1];
        int left = 1;
        int right = n-2;
        int ans =0;
        while(left<=right){
            if(leftHeight<rightHeight){
               leftHeight = Math.max(height[left],leftHeight);
               if(height[left]< leftHeight){
                ans +=leftHeight-height[left];
               }
               left++;
            }
            else{
               rightHeight = Math.max(height[right],rightHeight);
               if(height[right]<rightHeight){
                ans +=rightHeight-height[right];
               }
               right--;
            }
        }
        return ans;
    }
}