class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==1)
        {
            return 1;
        }
        vector<int> temp(255,-1);
        int n= s.size();
        int left = 0;
        int right = 0;
        int maxLen=0;
        while(right<n)
        {
            if(temp[s[right]]!=-1) left = max(left,temp[s[right]]+1);
             
             temp[s[right]]=right;
             //cout<<right<<" "<<left<<endl;
             maxLen = max(maxLen,right-left+1);
            right++;
        }
   return maxLen;
    }
};