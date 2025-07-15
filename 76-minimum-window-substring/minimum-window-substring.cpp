class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> sm;
        unordered_map<char,int> tm;
        for(char c : t){
            tm[c]++;
        }
        int match = tm.size();
        int minLen = s.size()+1;
        int left = 0;
        int right = 0;
        int start =-1;
        while(right<s.size())
        {
            char ch = s[right];
            sm[ch]++;
            if(sm[ch]==tm[ch]) match--;
            while(match==0 && left<=right)
            {
                if(minLen>right+1-left) {
                    start = left;
                    minLen=right+1-left;
                }
                char temp = s[left];
                sm[temp]--;
                left++;
                if(tm.find(temp) != tm.end() && sm[temp]<tm[temp]) match++;
            }
            right++;
        }

        if(start!=-1) return s.substr(start,minLen);
        else return "";
        
    }
};