class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s: tokens){
           if(s!="+" && s!="-" && s!="/" && s!="*"){
               st.push(stoi(s));
           }
           else if (s=="+"){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b+a);
           }
           else if (s=="-"){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b-a);
           }
           else if (s=="/"){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b/a);
           }
           else {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b*a);
           }
        }
        return st.top();
    }
};