class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
     int minspeed = 1; // minimum no. of bananas in a pile 
     int maxspeed = piles[0];
     for(int i : piles){
        if(i > maxspeed) maxspeed = i; // maximum no of bananas monkey can eat in minimum hours 
     }
     int mid =0;
     int ans = 0;
     while(minspeed<=maxspeed){
        mid = minspeed + (maxspeed-minspeed)/2 ;
        long long  k =  0;
        for(int i=0;i<piles.size();i++){
            k += (long long) (piles[i] + mid - 1)/ mid;//ceil of number 
        }
        if (k > h) minspeed = mid +1;
        else{
            ans = mid;
            maxspeed= mid -1;
        }
        
     }
     return ans;
    }
};