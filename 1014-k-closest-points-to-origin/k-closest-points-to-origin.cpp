class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;

        vector<vector<int>> ans;
        for(vector<int> temp : points){
            int d =0;
            d = pow(temp[0],2)+pow(temp[1],2);
            pq.push({d,{temp[0],temp[1]}});
        }
        while(!pq.empty()){
           auto t = pq.top();
           pq.pop();
           ans.push_back(t.second);
           if(ans.size()==k) return ans;
        }
        return ans;
        
    }
};