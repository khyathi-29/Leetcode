class Solution {
    public int longestMountain(int[] arr) {
        int maxLen = 0;
        int j = 0;
        int n = arr.length;
        while(j<n)
        {
            int i = j;
            if(i< n-1 && arr[i]<arr[i+1])
            {
                while(i<n-1 && arr[i]<arr[i+1]) i++;
                while(i<n-1 && arr[i] > arr[i+1]) i++;
                if(arr[i-1]>arr[i]) maxLen = Math.max(maxLen,i+1-j);
                j = i;
            }
            else j = i+1;
            
        }
        return maxLen;
    }
}