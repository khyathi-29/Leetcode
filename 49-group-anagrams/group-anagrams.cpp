// 128 ASCII char
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> a;
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++)
        {
            vector<int> temp(128,0);
            for(char c: strs[i])
            {
               temp[c]++;
            }
            if(a.find(temp)==a.end())
            {
                a[temp] = {strs[i]};
            }
            else a[temp].push_back(strs[i]);
        }
        for(auto i = a.begin();i!=a.end();i++)
        {
            ans.push_back(i->second);
        }
        return ans;
    }
};