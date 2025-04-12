class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n,0);
        stack<vector<int>> st;
        for( string s: logs){
            stringstream ss(s);
          string id,task,time;
          getline(ss,id,':');
          getline(ss,task,':');
          getline(ss,time,':');
          if(task=="start") st.push({stoi(id),stoi(time)});
          else{
            if(!st.empty() && stoi(id) == st.top()[0]){
                int duration =1+stoi(time)-st.top()[1];
                ans[stoi(id)]+=duration;
                st.pop();
                if(!st.empty()) ans[st.top()[0]]-=duration;//parent looses childs duration
                
            }
          }

        }
        return ans;
        
    }
};