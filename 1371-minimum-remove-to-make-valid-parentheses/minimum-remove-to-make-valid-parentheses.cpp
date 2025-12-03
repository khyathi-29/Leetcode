class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if(c=='(') st.push(i);
            else if(c==')'){
                if(st.empty()==true) s[i]='*';
                else st.pop();
            }
            else continue;
        }
        while(!st.empty()){
            int j = st.top();
            s[j]='*';
            st.pop();
        }
        string ans ="";
        for(int i=0;i<s.length();i++){
            if(s[i]!='*'){
                ans +=s[i];
            }
        }
        return ans;
    }
};