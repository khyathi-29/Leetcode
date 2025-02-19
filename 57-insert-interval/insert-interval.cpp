class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = newInterval[0];
        int end = newInterval[1];
        vector<vector<int>> result;
        if(intervals.size()==0) return {newInterval};
        int i=0;
        while(i < intervals.size() && intervals[i][1] < start){
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<end;
            result.push_back(intervals[i]);
            i++;

        }
        //start = min(intervals[i][0],start);
       // end = max(intervals[i][1],end);
       for(int j = i ;j <intervals.size(); j++)
        {
            if(intervals[j][0] <= end){
                start = min(intervals[j][0],start);
                end = max(intervals[j][1],end);
                cout<<start<<" "<<end<<endl;
            }
            else{
                cout<<"djkfgjt"<<endl;
                result.push_back({start,end});
                start = intervals[j][0];
                end = intervals[j][1];
            }
        }
        result.push_back({start,end});
       return result;
        
    }
};