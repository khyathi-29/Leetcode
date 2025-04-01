class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0;
        for(int i=0;i<gas.size();i++){
         total +=gas[i]-cost[i];
        }
        if(total<0) return -1;
        total=0;
        int ans = 0;
        for(int i=0;i< gas.size();i++){
            total += gas[i]-cost[i];
            if(total<0){
             ans = i+1;
             total=0;
            }
        }
        return ans;
    }
};