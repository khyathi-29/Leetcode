class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> f1;
        unordered_map<char,int> f2;
        if(s.size()<t.size()) return "";
        for( char c: t) f1[c]++;
        int match = f1.size();
        int start = 0;
        int end = -1;
        int len = INT_MAX;
        int left =0;
        int right =0;
        while(right<s.size()){
            char c = s[right];
            f2[c]++;
            if(f1.find(c)!=f1.end() && f2[c]==f1[c]) match--;
            while(match==0){
                if(right+1-left<len){
                    start =left;
                    end = right;
                    len = right+1-left;
                }
                f2[s[left]]--;
                if(f1.find(s[left])!=f1.end() && f1[s[left]]>f2[s[left]]) match++;
                left = left+1;
            }
            right++;
            
        }
        if(end==-1) return "";
        return s.substr(start,len);
        
    }
};