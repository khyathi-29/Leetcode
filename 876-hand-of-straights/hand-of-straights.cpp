class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        map<int,int> mp;//store frequency count
        for(int temp: hand){
           mp[temp]++;
        }
        sort(hand.begin(),hand.end());
        for(int num : hand){
            if(mp[num]>0){
                int freq = mp[num];
                for(int i= num ;i<num+groupSize;i++){
                    if(mp[i]<freq) return false;
                    else mp[i]=mp[i]-freq;
                }
            }
        }
        return true;
        
    }
};