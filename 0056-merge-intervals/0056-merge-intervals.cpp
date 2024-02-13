class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0)
        {
        return {};
        }
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> a;
        int end=intervals[0][1];
        int start=intervals[0][0];
        for(int i=1;i<intervals.size();i++)
        {
           if(intervals[i][0]<=end)
           {
              end = max(intervals[i][1],end); 
              start = min(intervals[i][0],start);
           }
           else
           {
               a.push_back({start,end});
               end = intervals[i][1];
               start = intervals[i][0];
               //a.push_back(intervals[i]);
           }


        }
        a.push_back({start,end});
        return a;
        
    }
};