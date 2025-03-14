class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string pattern = "";
        Helper(0,0,n,ans,pattern);
        return ans;
    }
    void Helper(int openP,int closeP,int n,vector<string>& ans,string& pattern)
    {
        if(openP==closeP && openP==n){
            ans.push_back(pattern);
            return;
        }
        if(openP < n){
            pattern += '(';
            Helper(openP+1,closeP,n,ans,pattern);
            pattern.pop_back();
        }
        if(closeP < openP){
            pattern += ')';
            Helper(openP,closeP+1,n,ans,pattern);
            pattern.pop_back();
        }
    }
};