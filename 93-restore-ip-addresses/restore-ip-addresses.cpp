class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> temp;
        vector<string> ans ;
        if(s.size()>12) return ans;
        Helper(0,s,temp,ans);
        return ans;
    }
    void Helper(int index ,string s, vector<string>& temp,vector<string>& ans)
    {
        if(index == s.size() && temp.size()==4)
        {
            ans.push_back(temp[0]+"."+temp[1]+"."+temp[2]+"."+temp[3]);
            return;
        }
        if(index==s.size()) return;
        if(temp.size()>4) return;
        int val = 0;
        string num = "";
        for(int i = index ;i< min(index+3,(int)s.size());i++)
        {
           val = val*10+ s[i]-'0';
           if(val>255 || (s[index]=='0') && i!=index) break;
           //removes invalid numbers greater than 255 and index with leading zeroes
           temp.push_back(s.substr(index, i+1-index));
           Helper(i+1,s,temp,ans);
           temp.pop_back();
        }
    }
};