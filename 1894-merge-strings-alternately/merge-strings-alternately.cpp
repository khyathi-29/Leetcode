class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        string ans = "";
        for(int i=0;i<max(m,n);i++){
            if(i<m) ans.push_back(word1[i]);
            if(i<n) ans.push_back(word2[i]);
        }
        return ans; 
    }
};