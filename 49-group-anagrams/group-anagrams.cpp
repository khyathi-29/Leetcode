// 128 ASCII char
// We use unorderedmap to store anagrams;
// we traverse each string and construct a frequency matrix of length 26 as there are only 26 letters
// then we make a frequency string by comma separated so that by mistake we dont get two strings not anagrams as same string
// if there exists same frequency string inside the map then we push our string into the vector
// else we create key value pair
// time complexity && space complexity is m*n where m is number of strings and n is length of string

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