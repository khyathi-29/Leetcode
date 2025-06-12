/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */
 
class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int peakIndex = getPeak(mountainArr);
        int ans = -1;
        ans = BS(0,peakIndex,target,mountainArr,true);
        if(ans!=-1) return ans;
        ans = BS(peakIndex,mountainArr.length()-1,target,mountainArr,false);
        return ans;
    }
    public int BS(int i,int j,int target,MountainArray m,boolean leftHalf)
    {
        while(i<=j)
        {
          int mid = i + (j-i)/2;
          int val = m.get(mid);
          if(val==target) return mid;
          else if(val>target) {
            if(leftHalf==true) j = mid-1;
            else i = mid+1;
          }
          else{
            if(leftHalf==true) i=mid+1;
            else j = mid-1;
          }
        }
        return -1;
    }
    public int getPeak(MountainArray m)
    {
        int i = 1;
        int j = m.length()-2;
        while(i<=j)
        {
            int mid = i + (j-i)/2;
            int n1 = m.get(mid-1);
            int n2 = m.get(mid);
            int n3 = m.get(mid+1);
            if(n2>n1&& n2>n3) return mid;
            else if(n2>n1&& n2<n3) i = mid+1;
            else j = mid-1;
        }
         return -1;
    }
}