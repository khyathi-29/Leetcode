class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0;
        int j=0;
        vector<vector<int>> ans;
        while(i<firstList.size() && j<secondList.size()){
            int t1 = max(firstList[i][0],secondList[j][0]);
            int t2 = min(firstList[i][1],secondList[j][1]);
            if(t1<=t2){//for intersection to exist this should be valid
                ans.push_back({t1,t2});
            }
            if(firstList[i][1] < secondList[j][1]) i++;//traversing next elements
            else j++;
        }
        return ans;
        
    }
};