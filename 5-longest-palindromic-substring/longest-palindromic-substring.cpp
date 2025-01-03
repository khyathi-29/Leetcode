class Solution {
public:
    string longestPalindrome(string s) {
    // 1.Here time complexity is O(n*n) and space is o(n) to store palindrome
    // 2. first we check palindrom have middle at each index for odd length and even length case
    // 3. If its greater than the length of maxpalindrom till now note its start and end and update its length
    // 4. copy it and return it.

    if(s.size()==1) return s;
     int start = 0;
     int end =0;
     int length=1;
     //odd length palindrome check
     for(int i=0;i<s.size();i++)
     {
          int l = i;
          int r = i;
          while(l>-1 && r<s.size())
          {
            if(s[l]==s[r])
            {
                int len = r-l+1;
                if(len>length)
                {
                    start=l;
                    end=r;
                    length = len;
                }
                l--;
                r++;
            }
            else break;
          } 
     }
     // even length check
     for(int i=0;i<s.size()-1;i++)
     {
          int l = i;
          int r = i+1;
          while(l>-1 && r<s.size())
          {
            if(s[l]==s[r])
            {
                int len = r-l+1;
                if(len>length)
                {
                    start=l;
                    end=r;
                    length = len;
                }
                l--;
                r++;
            }
            else break;
          } 
     }
     string ans="";
     for(int i=start;i<=end;i++)
     {
        ans+=s[i];
     }
     return ans;
    }


};