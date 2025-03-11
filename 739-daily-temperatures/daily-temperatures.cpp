class Solution {
public:
// use monotonic stack to present temparatures like next element and stuff
    vector<int> dailyTemperatures(vector<int>& temparatures) {
        vector<int> ans(temparatures.size(),0);
        stack<pair<int,int>> st;
        st.push(make_pair(temparatures[0],0));
        for(int i=1 ; i<temparatures.size();i++){
            while(!st.empty() && st.top().first < temparatures[i]){
                ans[st.top().second] = i-st.top().second;
                st.pop();
            }
            st.push(make_pair(temparatures[i],i));
        }
       return ans; 
    }
};