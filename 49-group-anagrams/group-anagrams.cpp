class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> temp;
        vector<vector<string>> ans;
        for( string s: strs){
            vector<int> fr(26,0);
            for( char c: s){
                fr[c-'a']++;
            }
            string tem ="";
            for(int i : fr) tem= tem+to_string(i)+" ";
            if(temp.find(tem)==temp.end()) temp[tem]={s};
            else temp[tem].push_back(s);
        }
        for(auto i = temp.begin();i!=temp.end();i++) ans.push_back(i->second);
        return ans;
    }
};