/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr){
        int index = findInMountainArrayHelper(target,0,mountainArr.length()-1, mountainArr);
        // now we got the mountain index then we need to do BS to its left and righ;
        if(mountainArr.get(index)==target) return index;
        int val = BS(true,0,index-1,target,mountainArr);
        cout<<val<<endl;
        if(val!=-1) return val;
        val = BS(false,index+1,mountainArr.length()-1,target,mountainArr);
        return val;
        
    }
    int BS(bool asc , int low, int high,int target, MountainArray &mountainArr )
    {
           while(low<=high)
           {
             int mid = (low + (high-low)/2);
             int val = mountainArr.get(mid);
             if(val==target) return mid;
             else if( val > target){
                if(asc==true) high = mid-1;
                else low = mid+1;
             }
             else{
                if(asc==true) low = mid+1;
                else high = mid-1;
             }
           }
           return -1;
    }
    int findInMountainArrayHelper(int target, int l, int h, MountainArray &mountainArr) {
        int low = l;
        int high = h;
        if(mountainArr.get(1)<mountainArr.get(0))
        {
            return 0;
        }
        if(mountainArr.get(high)>mountainArr.get(high-1))
        {
            return high;
        }
        low++;
        high--;
        while(low<=high){
            int mid = low + (high-low)/2;
            int before = mountainArr.get(mid-1);
            int val = mountainArr.get(mid);
            int after = mountainArr.get(mid+1);
            if(val>before && val>after) return mid;
            else if( val > before && after> val) low = mid+1;
            else if(val < before && after< val) high = mid-1;
            
        }
        return -1;
    }
};