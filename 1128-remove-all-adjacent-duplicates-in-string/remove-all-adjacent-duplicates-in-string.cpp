class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int i = 0;
        while(i<s.size()){
            if(st.empty()==false && st.top()==s[i]) st.pop();
            else st.push(s[i]);
            i++;
        }
        string ans ="";
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};