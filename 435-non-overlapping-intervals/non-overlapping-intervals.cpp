class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int count = 0;
        int previous_e = intervals[0][1];
        int previous_s = intervals[0][0];
        for(int i=1;i<intervals.size();i++)
        {
            cout<<i<<" "<<previous_e<<endl;
            if(intervals[i][0]<previous_e)
            {
                count++;
                previous_e = min(previous_e,intervals[i][1]);

            }
            else{
                previous_e = intervals[i][1];
                previous_s = intervals[i][0];
                
            }
        }
        return count;
        
    }
};