class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        int n = s.length();
        for(int i=0;i<n;i++)
        {
          if(s[i]=='(' || s[i]=='{' || s[i]=='[')
          {
            a.push(s[i]);
          }
          else
          {
            if(a.size()==0) return false;
            if((s[i]==')' && a.top()=='(') || (s[i]=='}' && a.top()=='{') || (s[i]==']' && a.top()=='['))
            {
               a.pop();
            } 
            else return false;
    
          }
        }
        if(a.size()!=0) return false;
        return true;
    }
};