class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==1)
        {
            return 1;
        }
        vector<int> a(255,-1);
        int len=0;
        int maxlen=0;
        int left=0;
        int right=0;
        while(right<s.size())
        {
            if(a[s[right]]!=-1)
            {
              left = max(a[s[right]]+1,left);
            }
            a[s[right]]=right;
            maxlen=max(maxlen,right-left+1);
            right++;
        }
        return max(maxlen,len);
        
        
    }
};