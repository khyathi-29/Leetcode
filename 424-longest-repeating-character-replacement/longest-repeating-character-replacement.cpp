class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> check;
        int ans=0;
        int left =0, right = 0, maxfreq = 0;
        while(right<s.size())
        {
            check[s[right]-'A']++;
            maxfreq= max(maxfreq,check[s[right]-'A']);
            cout<<"r l m "<<right<<" "<<left<<" "<<maxfreq<<endl;
            if((right - left+1)-maxfreq>k){
                check[s[left]-'A']--;
                left++;
            }
              ans = max(ans,right+1-left);
              right++;
              cout<<"maxlen"<<ans<<endl;

        }
        return ans;
        
    }
};