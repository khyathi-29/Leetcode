class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<string> temp;
        int index = 0;
        int nums = 0;
        Helper(0,ans,temp,s);
        return ans;
    }
     void Helper(int index, vector<string>& ans, vector<string>& temp,string s)
        {
            if(temp.size()==4 && index==s.size()) {
                string temp1 = temp[0]+"."+temp[1]+"."+temp[2]+"."+temp[3];
                ans.push_back(temp1);
                return;
            }
            if(index==s.size() || temp.size()==4) return;
            int nums = 0;
            for(int i= index; i< min(index+3,(int)s.size());i++)
            {
                    int val = s[i]-'0';
                    nums = nums*10 + val;
                    if(nums>255) break;
                    string ss = s.substr(index, i-index+1);
                    if(ss.size()>1 && ss[0]=='0') break;
                    temp.push_back(ss);
                    Helper(i+1,ans,temp,s);
                    temp.pop_back();
            }
            
        }
};