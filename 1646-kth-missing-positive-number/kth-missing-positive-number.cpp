class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size()-1;
       while(low<=high){
        int mid = low + (high-low)/2;
        int numbersmissing = arr[mid]-1-mid;
        if(numbersmissing>=k) high = mid-1;
        else low = mid+1;
       }
       return k+high+1;
        
    }
};