class Solution {
public:
    bool isSubstringPresent(string ss) {
        unordered_set<string> s;
        for(int i=0;i<ss.size()-1; i++)
        {
            s.insert(ss.substr(i, 2));
        }
        reverse(ss.begin(),ss.end());
        for(int i=0;i<ss.size()-1; i++)
        {
            if(s.find(ss.substr(i,2))!=s.end()) return true;
        }

        return false;
    }
};