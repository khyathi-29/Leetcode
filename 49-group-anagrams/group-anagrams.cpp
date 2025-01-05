// 128 ASCII char
// We use 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>> a;
       // map<vector<int>,vector<string>> a; not possible to have vector<int> as key for unordered map
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++)
        {
            vector<int> temp(26,0);
            for(char c: strs[i])
            {
               temp[c-'a']++;
            }
            string s = "";
            s=to_string(temp[0]);
            for(int i=0;i<26;i++)
            {
                s = s+","+to_string(temp[i]);
            }
            if(a.find(s)==a.end())
            {
                a[s] = {strs[i]};
            }
            else a[s].push_back(strs[i]);
        }
        for(auto i = a.begin();i!=a.end();i++)
        {
            ans.push_back(i->second);
        }
        return ans;
    }
};