class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        vector<int> indexRemoval;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(i);//index where bracket opens
            else if(s[i]==')'){
             if(st.empty()==true) s[i]='*';
             else st.pop();
            }
            else continue;
        }
        while(!st.empty()){
           s[st.top()]='*';
           st.pop(); 
        }//make the existing open brackets without any closed as invalid;
        string temp="";
        for(int i=0;i<s.size();i++){
         if(s[i]!='*') temp+=s[i];
        }
        return temp;
    }
};